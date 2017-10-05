//flood fill trial pastebin.com/vzCTdmUn

#include<stdio.h>
#include<GL/glut.h>
#define offset 250
void setPixel(int x, int y)
{
	glColor3f(255.0, 255.0, 255.0);
	glBegin(GL_POINTS);
	glVertex2i(offset + x, offset + y);
	glEnd();
	glFlush();
}
void drawsquare()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void init()
{

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawsquare();
	//floodfill()
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowSize(500, 500);
	//glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}