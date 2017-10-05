#include<GL/glut.h>
#include<iostream>
GLint offset = 250;
GLint Rx, Ry, xc, yc;
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setAxes()
{
	setDrawingColor(0.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glEnd();
	glFlush();
}

void setPixel(GLint x,GLint y)
{
	setDrawingColor(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(offset+xc+x,offset+ yc+y);
	glEnd();
	glFlush();
}
void ellipse(GLint Rx,GLint Ry)
{
	int Rx2 = 2 * Rx*Rx;
	int Ry2 = 2 * Ry*Ry;
	int px = 0;
	int py = Rx2*Ry;
	int x = 0;
	int y = Ry;
	int p;
	setPixel(x, y);
	p = Ry*Ry - Rx*Rx*Ry + 0.25*Rx*Rx;
	while (px < py)
	{
		x++;
		px = px + Ry2;
		if (p < 0)
			p = p + Ry*Ry + px;
		else
		{
			y--;
			py = py - Rx2;
			p = p + Ry*Ry + px - py;
		}
		setPixel(x, y);
		setPixel(-x, y);
		setPixel(x, -y);
		setPixel(-x, -y);
	}
	p = Ry*Ry*(x + 0.5)*(x + 0.5) + Rx*Rx*(y - 1)*(y - 1) - Rx*Rx*Ry*Ry;
	while (y > 0)
	{
		y--;
		py = py - Ry2;
		if (p>0)
			p = p + Rx*Rx - py;
		else
		{
			x++;
			px = px + Rx2;
			p = p + Rx*Rx - py + px;
		}
		setPixel(x, y);
		setPixel(-x, y);
		setPixel(x, -y);
		setPixel(-x, -y);
	}
}
void filled()
{

	int x = 100;
	int y = 100;
	int r = 50;
	//This here is sin(45) but i just hard-coded it.
	float sinus = 0.70710678118;
	//This is the distance on the axis from sin(90) to sin(45). 
	int range = r / (2 * sinus);
	for (int i = r; i >= range; --i)
	{
		int j = sqrt(r*r - i*i);
		for (int k = -j; k <= j; k++)
		{
			//We draw all the 4 sides at the same time.
			setPixel(x - k, y + i);
			setPixel(x - k, y - i);
			setPixel(x + i, y + k);
			setPixel(x - i, y - k);
		}
	}
	//To fill the circle we draw the circumscribed square.
	range = r*sinus;
	for (int i = x - range + 1; i < x + range; i++)
	{
		for (int j = y - range + 1; j < y + range; j++)
		{
			setPixel(i, j);
		}
	}

}
void display1()
{
	setAxes();
	ellipse(Rx,Ry);
}
void display2()
{
	setAxes();
	filled();
}
int main(int argc, char **argv)
{
	std::cout << "Enter the center and the two radii\n";
	std::cin >> xc >> yc >> Rx >> Ry;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OPENGL1");
	init();
	glutDisplayFunc(display1);
	glutCreateWindow("OPENGL2");
	init();
	//glutDisplayFunc(display2);
	glutMainLoop();
	return 0;
}