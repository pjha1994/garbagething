//Fixed flood fill
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include<iostream>
#include<stdio.h>
using namespace std;
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void floodfill(int x, int y,Color old,Color fill)
{
	Color current;
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &current);
	setPixel(x, y);
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
	Color old, fillColor;
        fillColor.r =  0.0;fillColor.g= 1.0;fillColor.b= 1.0;
	glReadPixels(151, 151, 1.0, 1.0, GL_RGB, GL_FLOAT, &old);
	floodfill(151, 151,old,fillColor);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
        /*GLenum err = glewInit();
if (GLEW_OK != err)
{
    fprintf(stderr, "Error %s\n", glewGetErrorString(err));
    exit(1);
}
fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

if (GLEW_ARB_vertex_program)
    fprintf(stdout, "Status: ARB vertex programs available.\n");

if (glewGetExtension("GL_ARB_fragment_program"))
    fprintf(stdout, "Status: ARB fragment programs available.\n");

if (glewIsSupported("GL_VERSION_1_4  GL_ARB_point_sprite"))
    fprintf(stdout, "Status: ARB point sprites available.\n");*/
	init();
	glutDisplayFunc(display);
	glutMainLoop();
        return 0;
}
