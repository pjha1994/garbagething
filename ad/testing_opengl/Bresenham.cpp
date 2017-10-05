#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int cor_1, cor_2, cor_3, cor_4;
int offset = 250;
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
	glVertex2i(x,y);
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
void bresenham(int cor_1, int cor_2,int cor_3,int cor_4)
{
	setPixel(offset + cor_1, offset + cor_2);
	int dx, dy, D;
	dx = abs(cor_3 - cor_1);
	dy = abs(cor_4 - cor_2);
	if (dx >dy)
	{
		int m = 2 * dy;
		D = m - dx;

		for (cor_1 = cor_1 + 1; cor_1 <= cor_3; cor_1++)
		{
			if (D > 0)
			{
				cor_2 = cor_2 + 1;
				setPixel(offset + cor_1, offset + cor_2);
				D = D + (m - 2 * dx);
			}
			else
			{
				setPixel(offset + cor_1, offset + cor_2);
				D = D + m;
			}
		}
	}
	else if ((dx)<(dy))
	{
		int m = 2*dx;
		D = m - dy;
		for (cor_2 = cor_2 + 1; cor_2 < cor_4; cor_2++)
		{
			if (D > 0)
			{
				cor_1 = cor_1 + 1;
				setPixel(offset + cor_1, offset + cor_2);
				D = D + m - 2 * dy;
			}
			else
			{
				setPixel(offset + cor_1, offset + cor_2);
				D = D + m;
			}
		}
	}
	else if (dx == dy&&(dx!=0))
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(cor_1, cor_2);
		glVertex2i(cor_3,cor_4);
		glEnd();
		glFlush();
	}
	else if ((dx == 0)&&(dy!=0))
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(cor_1, cor_2);
		for (int i = 0; i < 50; i++)
		{
			glVertex2i(cor_3, cor_4+i);
		}
		glEnd();
		glFlush();
	}
	else if ((dy == 0)&&(dx!=0))
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(cor_1, cor_2);
		for (int i = 0; i < 500; i++)
		{
			glVertex2i(cor_3 + i, cor_4);
		}
		glEnd();
		glFlush();
	}
	else
		exit(0);
}
void display()
{
	setAxes();
	if (cor_1 > cor_3)
		bresenham(offset+cor_3,offset+ cor_4,offset+ cor_1,offset+ cor_2);
	else
		bresenham(offset+cor_1,offset+ cor_2,offset+ cor_3,offset+ cor_4);
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
