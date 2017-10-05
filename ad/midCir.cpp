#include<GL/glut.h>
#include<iostream>
GLint offset = 250;
GLint xc, yc,r;
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setAxes()
{
	setDrawingColor(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void setPixel(GLint x, GLint y,GLint xc,GLint yc)
{
	setDrawingColor(0.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(offset+xc + x,offset+ yc + y);
	glEnd();
	glFlush();
}
void drawCircle()
{
	GLint p = 1 - r;
	GLint x = r;
	GLint y = 0;
	
	while (x>=y)
	{
		setPixel(x, y, xc, yc);
		setPixel(-x, y, xc, yc);
		setPixel(x,-y, xc, yc);
		setPixel(-x, -y, xc, yc);
		setPixel(y, x, xc, yc);
		setPixel(-y, x, xc, yc);
		setPixel(y, -x, xc, yc);
		setPixel(-y, -x, xc, yc);
		y++;
		if (p < 0)
			p = p + 2 * y + 1;
		else
		{
			x--;
			p = p + 2 * (y - x) + 1;
		}
	}
}
void display()
{
	setAxes();
	drawCircle();
}
int main(int argc,char **argv)
{
	std::cout << "Enter center and radius of the circle\n";
	std::cin >> xc >> yc >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TRIAL 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}