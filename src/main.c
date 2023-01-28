#include "game.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(X, Y);
	glutCreateWindow(TITLE);

	init();

	glutKeyboardFunc(key_down);
	glutKeyboardUpFunc(key_up);
	glutDisplayFunc(draw);
	glutTimerFunc(UPDATE_INTERVAL, update, 0); /* 0 is rubbish value */
	glutMainLoop();

	return 0;
}
