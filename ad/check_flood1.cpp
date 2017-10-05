//Fixed flood fill pastebin.com/yjguQm5t
#include<stdio.h>
#include<GL/glut.h>
#include<iostream>
#define offset 250
GLfloat currentColor[3], oldColor[3], fillColor[3];
struct Color
{
	GLfloat r, g, b;
};
void setPixel(int x, int y)
{
	glColor3f(0.0, 255.0, 255.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void drawsquare()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(10, 10);
	glVertex2i(410, 10);
	glVertex2i(410, 10);
	glVertex2i(410, 410);
	glVertex2i(410, 410);
	glVertex2i(10, 410);
	glVertex2i(10, 410);
	glVertex2i(10, 10);
	glEnd();
	glFlush();
}
void init()
{

	glClearColor(0.0, 0.0, 0.0, 1.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void floodfill(int x, int y,Color old,Color fill)
{
	Color current;
	//glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, currentColor);
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &current);
	//printf("current is %f%f%f", currentColor[0], currentColor[1], currentColor[2]);
	setPixel(x, y);
	//if (currentColor[0] == oldColor[0] && currentColor[1] == oldColor[1] && currentColor[2] == oldColor[2]);
	if (current.r==old.r&&current.g==old.g&&current.b==old.b)
	{
		floodfill(x, y + 1, old, fill);
		floodfill(x, y - 1, old, fill);
		floodfill(x - 1, y, old, fill);
		floodfill(x + 1, y, old, fill);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawsquare();
	//fillColor[0] = 0.0; fillColor[1] = 1.0; fillColor[2] = 1.0;
	Color old, fill = {0.0,1.0,1.0};
	glReadPixels(151, 151, 1.0, 1.0, GL_RGB, GL_FLOAT, &old);
	//printf("old is  %f%f%f", oldColor[0], oldColor[1], oldColor[2]);
	floodfill(151, 151,old,fill);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}