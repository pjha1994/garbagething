//Bresenhamline line

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS 1
int a, b, c, d;
void setPixel(int x, int y);
void bresenhamline(int x1, int y1, int x2, int y2);
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000, -1000, 1000);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);

	glColor3f(1.0, 1.0, 1.0);
	bresenhamline(0, -500, 0, 500);
	bresenhamline(-500, 0, 500, 0);
	glColor3f(1.0, 1.0, 0.0);
	bresenhamline(a, b, c, d);
	glutSwapBuffers();
}

void bresenhamline(int x1, int y1, int x2, int y2)
{
	int slope;
	int dx, dy, incE, incNE, d, x, y;

	if (abs(y2 - y1) <= abs(x2 - x1))
	{
		// Reverse lines where x1 > x2
		if (x1 > x2)
		{
			bresenhamline(x2, y2, x1, y1);
			return;
		}
		dx = x2 - x1;
		dy = y2 - y1;
		// Adjust y-increment for negatively sloped lines
		if (dy < 0)
		{
			slope = -1;
			dy = -dy;
		}
		else
		{
			slope = 1;
		}
		// Bresenham constants
		incE = 2 * dy;
		incNE = 2 * dy - 2 * dx;
		d = 2 * dy - dx;
		y = y1;
		// Blit
		for (x = x1; x <= x2; x++)
		{
			setPixel(x, y);
			if (d <= 0)
			{
				d += incE;
			}
			else
			{
				d += incNE;
				y += slope;
			}
		}
	}
	else
	{
		// Reverse lines where y1 > y2
		if (y1 > y2)
		{
			bresenhamline(x2, y2, x1, y1);
			return;
		}
		dx = x2 - x1;
		dy = y2 - y1;
		// Adjust x-increment for negatively sloped lines
		if (dx < 0)
		{
			slope = -1;
			dx = -dx;
		}
		else
		{
			slope = 1;
		}
		// Bresenham constants
		incE = 2 * dx;
		incNE = 2 * dx - 2 * dy;
		d = 2 * dx - dy;
		x = x1;
		// Blit
		for (y = y1; y <= y2; y++)
		{
			setPixel(x, y);
			if (d <= 0)
			{
				d += incE;
			}
			else
			{
				d += incNE;
				y += slope;
			}
		}
	}
}

void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

int main(int argc, char** argv)
{
	printf("Enter (x1,y1)\n");
	scanf_s("%d%d", &a, &b);
	printf("Enter (x2,y2)\n");
	scanf_s("%d%d", &c, &d);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(" Bresenham line ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
