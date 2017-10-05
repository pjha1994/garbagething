#include<GL/glut.h>
#include<iostream>
using namespace std;
int ct = 0;

struct Point{
	GLint x;
	GLint y;
};
struct Color{
	GLfloat r, g, b;
}boundary, fill_boundary/*, oldColor, fillColor*/;
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glColor3f(d, e, f);
}
void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLint x, GLint y, Color setColor)
{
	setDrawingColor(setColor.r, setColor.g, setColor.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glEnd();
	glFlush();
}
void DDA(Point a, Point b)
{
	Color myLineColor = { 1.0, 0.0, 0.0 };
	GLint x1 = a.x;
	GLint y1 = a.y;
	GLint x2 = b.x;
	GLint y2 = b.y;
	setPixel(x1, y1, myLineColor);
	setPixel(x2, y2, myLineColor);
	GLint dx = x2 - x1;
	GLint dy = y2 - y1;
	GLint steps = abs(dy);//ASSUMED
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	GLfloat incrx = dx / float(steps);
	GLfloat incry = dy / float(steps);
	for (GLint i = 0; i < steps; i++)
	{
		x1 = x1 + incrx;
		y1 = y1 + incry;
		setPixel(x1, y1, myLineColor);
	}
}
void drawSquare()
{
	Point a, b, c, d;
	a.x = a.y = 250;
	b.x = 300; b.y = 250;
	c.x = c.y = 300;
	d.x = 250; d.y = 300;
	DDA(a, b);
	DDA(b, c);
	DDA(c, d);
	DDA(d, a);
}

void floodFill(int x, int y,GLfloat fillColor,GLfloat oldColor)
{
    GLfloat currentColor[3];
    glReadPixels(x, y, 1, 1, GL_UNSIGNED_BYTE, GL_RGBA, &currentColor);
	cout << "\n\n\nCurrentColor ==";
	cout << currentColor.r << currentColor.g << currentColor.b<<"\n\n";
	if (currentColor[0] == oldColor[0]&&currentColor[0] == oldColor[0]&&currentColor[0] == oldColor[0]){
		setPixel(x, y, fillColor);
		//glReadPixels(x, y, 1, 1, GL_FLOAT, GL_RGBA, &currentColor);
		floodFill(x + 1, y, fillColor, oldColor);
		floodFill(x, y + 1, fillColor, oldColor);
		floodFill(x - 1, y, fillColor, oldColor);
		floodFill(x, y - 1, fillColor, oldColor);
	}
}

void display()
{

        GLfloat fillColor[3],oldColor[3];
	glClear(GL_COLOR_BUFFER_BIT);
	setAxes();
	drawSquare();
        fillColor = { 0.0, 0.0, 1.0 };
	glReadPixels(275, 275, 1, 1, GL_UNSIGNED_BYTE, GL_RGBA, &oldColor);
	cout << "\nold color is ==" << oldColor.r << oldColor.g << oldColor.b<<"\n\n";
	cout << "\nfill color is ==" << fillColor.r << fillColor.g << fillColor.b<<"\n\n";
	floodFill(275, 275, fillColor, oldColor);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("opengl");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}