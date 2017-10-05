#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct das
{
	int x;
	int y;
} p[100000];

int top;
float oldcolor[3], fillcolor[3];

void push(int x, int y)
{
	top++;
	if (top == 100000)
		exit(0);
	p[top].x = x;
	p[top].y = y;
}

void pop(int *x, int *y)
{
	*x = p[top].x; *y = p[top].y;
	top--;
}

void setPixel(int x, int y)
{
	glColor3fv(fillcolor);
	//glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}

void floodfill(int x, int y)
{
	int xc, yc;
	push(x, y);
	float currentcolor[3];
	setPixel(x, y);

	while (top>0)
	{
		pop(&xc, &yc);
		glReadPixels(xc + 1, yc, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);
		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{
			setPixel(xc + 1, yc); push(xc + 1, yc);
		}

		glReadPixels(xc - 1, yc, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);
		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{
			setPixel(xc - 1, yc); push(xc - 1, yc);
		}

		glReadPixels(xc, yc + 1, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);
		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{
			setPixel(xc, yc + 1); push(xc, yc + 1);
		}

		glReadPixels(xc, yc - 1, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);
		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{
			setPixel(xc, yc - 1); push(xc, yc - 1);
		}
	}
}



void drawPolygon()
{
	glColor3f(1.0, 1.0, 1.0);
	//glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(100, 100);
	glVertex2f(100, 400);
	glVertex2f(100, 400);
	glVertex2f(400, 400);
	glVertex2f(400, 400);
	glVertex2f(400, 100);
	glVertex2f(400, 100);
	glVertex2f(100, 100);
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500,-1,1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	drawPolygon();
	fillcolor[0] = 0.0; fillcolor[1] = 255.0; fillcolor[2] = 0.0;
	glReadPixels(300, 300, 1.0, 1.0, GL_RGB, GL_FLOAT, oldcolor);
	floodfill(101, 101);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(" ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
