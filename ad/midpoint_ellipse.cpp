#include<iostream>
#include<GL/glut.h>
#define offset 250
#define ROUND(a) ((int)(a+0.5))
int xCenter,yCenter,Rx , Ry;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(d, e, f);
}
void setPixel(int x, int y)
{
	setDrawingColor();
	glBegin(GL_POINTS);
	glVertex2i(offset+x, offset+y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0,0.0,1.0);
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
void ellipseMidPoint(int xCenter, int yCenter, int Rx, int Ry)
{
	setAxes();
	int Rx2 = Rx*Rx;
	int Ry2 = Ry*Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2*y;
	void ellipsePlotPoints(int,int,int,int);
	ellipsePlotPoints(xCenter, yCenter, x, y);
	p = ROUND(Ry2 - (Rx2*Ry) + (0.25*Rx2));
	while (px < py)
	{
		x++;
		px += twoRy2;
		if (p < 0)
			p += Ry2 + px;
		else{
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}

	p = ROUND(Ry2*(x + 0.5)*(x + 0.5) + Rx2*(y - 1)*(y - 1) - Rx2*Ry2);
	while (y > 0)
	{
		y--;
		py -= twoRx2;
		if (p>0)
			p += Rx2 - py;
		else{
			x++;
			px += twoRy2;
			p += Rx2 - py + px;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
}
void ellipsePlotPoints(int xCenter, int yCenter, int  x, int y)
{
	setPixel(xCenter + x, yCenter + y);
	setPixel(xCenter - x, yCenter + y);
	setPixel(xCenter + x, yCenter - y);
	setPixel(xCenter - x, yCenter - y);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	ellipseMidPoint(xCenter,yCenter, Rx, Ry);
}
int main(int argc,char **argv)
{
	std::cout << "Enter the xCente, yCenter,rx and ry\n";
	std::cin >> xCenter >> yCenter >> Rx >> Ry;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}