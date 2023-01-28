#include "game.h"

void init()
{
	glClearColor(0,0,0,0);

	/* define a new orthographic projection matrix							*/
	/* glut deafult uses bottom-left to top-right drawing mode				*/
	/* so we need to switch the y-axis to make it top-left to bottom-right	*/
	gluOrtho2D(0,WIDTH,HEIGHT,0);

	init_player();
	init_keys();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	raycast();
	if (map_mode)
	{
		draw_map();
		draw_player();
	}

	glFlush();
}

void update(int rubbish)
{
	updt_player();

	glutPostRedisplay(); /* call new draw flag */
	glutTimerFunc(UPDATE_INTERVAL, update, 0);
}
