//Parametric parabola

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int cx, cy, a, b;
void drawaxes();
void display();
void drawparabola(int xc, int yc, int a);

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000, -1000, 1000);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

	cx = 0; cy = 0; a = 100;

	glColor3f(0, 255, 255);
	glPointSize(1);
	glBegin(GL_POINTS);
	drawparabola(cx, cy, a);
	glEnd();

	drawaxes();

	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(a, 2 * a);
	glVertex2f(a, -2 * a);
	glEnd();

	glFlush();
}

void drawparabola(int xc, int yc, int a)
{

	float xp, yp, i;
	for (i = 0; i<360; i++)
	{
		xp = xc + a*tan(3.14*(i / 180))*tan(3.14*(i / 180));
		yp = yc + 2 * a*tan(3.14*(i / 180));
		glVertex2f(xp, yp);
	}
}

void drawaxes()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i(0, -1000);
	glVertex2i(0, 1000);
	glVertex2i(-1000, 0);
	glVertex2i(1000, 0);
	glEnd();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(" Parametric parabola ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
