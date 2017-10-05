#include<glut.h>
#include<iostream>
#include<stdlib.h>
#define ROUND(a) ((int)(a+0.5))
using namespace std;
int cor_1, cor_2, cor_3, cor_4;
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
	glVertex2i(x, y);
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
void DDA(int cor_1, int cor_2, int cor_3, int cor_4)
{
	int dx, dy,step,offset=250;
	dx = (cor_3 - cor_1);
	dy = (cor_4 - cor_2);
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	setPixel(offset+cor_3, offset+cor_4);
	for (int i = 0; i < step; i++)
	{
		cor_1 = cor_1 + dx / step;
		cor_2 = cor_2 + dy / step;
		cout << "cor_1 = " << cor_1 << "  cor_2 = " << cor_2 << "\n";
		setPixel(offset+ROUND(cor_1), offset+ROUND(cor_2));
	}
}
void display()
{
	setAxes();
	if (cor_1 < cor_3)
		DDA(cor_1, cor_2, cor_3, cor_4);
	else
		DDA(cor_3, cor_4, cor_1, cor_2);
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> cor_1 >> cor_2 >> cor_3 >> cor_4;
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
