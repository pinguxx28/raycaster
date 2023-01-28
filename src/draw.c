#include "draw.h"

void draw_line(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	glEnd();
}

void draw_rect(int x, int y, int w, int h)
{
	glBegin(GL_QUADS);
		glVertex2i(x  , y  );
		glVertex2i(x+w, y  );
		glVertex2i(x+w, y+h);
		glVertex2i(x  , y+h);
	glEnd();
}

void draw_circle(int x, int y, int r)
{
	for (int i = 0; i < 360; ++i)
	{
		float radians = i * M_PI / 180;

		float x_pos = cos(radians) * r;
		float y_pos = sin(radians) * r;

		glBegin(GL_POINTS);
			glVertex2i(x + x_pos, y + y_pos);
		glEnd();
	}
}
