#include<GL/glut.h>
#include<iostream>
using namespace std;
#define offset 250
GLint in_1 , in_2 , length_sq;
struct Point{
	GLint x;
	GLint y;
};
struct Color{
	GLfloat r, g, b;
}boundary, fill_boundary, oldColor, currentColor,fillColor;
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glColor3f(d, e, f);
}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
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
void DDA(Point a, Point b,Color myLineColor)
{
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
void drawSquare(int x,int y,int length)
{
	Point a, b, c, d;
	a.x = x; a.y = y;
	b.x = x+length; b.y = y;
	c.x = x + length; c.y = y + length;
	d.x = x; d.y = y+length;
	Color myLineColor = { 1.0, 0.0, 0.0 };
	DDA(a, b,myLineColor);
	DDA(b, c, myLineColor);
	//myLineColor = { 0.0, 0.0, 1.0 }; For changing color of a line between two points
	DDA(c, d, myLineColor);
	DDA(d, a, myLineColor);
}
void boundaryFill(int x, int y, Color fill, Color boundary)
{
	Color current;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &current);
	if (boundary.r == current.r&&boundary.g != current.g&&boundary.b != current.b)	{
		setPixel(x, y, fill);
		boundaryFill(x + 1, y, fill, boundary);
		boundaryFill(x - 1, y, fill, boundary);
		boundaryFill(x, y + 1, fill, boundary);
		boundaryFill(x, y - 1, fill, boundary);
		boundaryFill(x+1, y + 1, fill, boundary);
		boundaryFill(x-1, y + 1, fill, boundary);
		boundaryFill(x+1, y - 1, fill, boundary);
		boundaryFill(x-1, y -1, fill, boundary);
	}
}
void floodFill(int x, int y,Color fillColor,Color oldColor)
{
	
    glReadPixels(x, y, 1, 1, GL_RGB,GL_FLOAT, &currentColor);
	if (currentColor.r == oldColor.r&&currentColor.g == oldColor.g&&currentColor.b == oldColor.b){
		setPixel(x, y, fillColor);
		floodFill(x + 1, y, fillColor, oldColor);
		floodFill(x, y + 1, fillColor, oldColor);
		floodFill(x - 1, y, fillColor, oldColor);
		floodFill(x, y - 1, fillColor, oldColor);
		floodFill(x+1, y + 1, fillColor, oldColor);
		floodFill(x-1, y + 1, fillColor, oldColor);
		floodFill(x+1, y -1, fillColor, oldColor);
		floodFill(x-1, y -1, fillColor, oldColor);
	}
}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON&&state == GLUT_DOWN)
		exit(0);
}
void flood_boundary_fill(int x,int y)
{
	boundary = { 1.0, 0.0, 0.0 };
	fill_boundary = { 0.8, .5, 0.0 };
	boundaryFill(x, y, fill_boundary, boundary);
	fillColor = { 0.0f, 0.0f, 1.0f };
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &oldColor);
	floodFill(x, y, fillColor, oldColor);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setAxes();
	drawSquare(offset+in_1,offset+in_2,length_sq);//Initial point and length os side
	flood_boundary_fill(offset+in_1+1, offset+in_2+1);//Mention an interior point of the region
	//drawSquare(0,0, 10);//Initial point and length of the side
	//flood_boundary_fill(5, 5);//Mention an interior point of the region
}
int main(int argc, char **argv)
{
	cout << "Enter initial coordinate and the length of the square\n";
	cin >> in_1 >> in_2 >> length_sq;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("opengl");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutMainLoop();
	return 0;
}