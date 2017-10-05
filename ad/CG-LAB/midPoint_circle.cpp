#include<glut.h>
#include<iostream>
#include<stdlib.h>
#define offset 250
using namespace std;
int center_x, center_y,radius;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(int x, int y)
{
	setDrawingColor(0.0, 255.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(offset+x,offset+ y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 255.0, 255.0);
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
void midCir(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int decisionOver2 = 1 - x;   // Decision criterion divided by 2 evaluated at x=r, y=0

	while (x >= y)
	{
		setPixel(x + x0, y + y0);
		setPixel(y + x0, x + y0);
		setPixel(-x + x0, y + y0);
		setPixel(-y + x0, x + y0);
		setPixel(-x + x0, -y + y0);
		setPixel(-y + x0, -x + y0);
		setPixel(x + x0, -y + y0);
		setPixel(y + x0, -x + y0);
		y++;
		if (decisionOver2 <= 0)
		{
			decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
		}
		else
		{
			x--;
			decisionOver2 += 2 * (y - x) + 1;   // Change for y -> y+1, x -> x-1
		}
	}
}
void display()
{
    	setAxes();
		midCir(center_x, center_y,radius);
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> center_x >> center_y>>radius;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
