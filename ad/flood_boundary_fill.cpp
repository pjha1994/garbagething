#include<GL/glut.h>
#include<iostream>
using namespace std;
int ct = 0;

struct Point{
	GLint x;
	GLint y;
};
struct Color{
	GLfloat r,g,b;
}fill1,oldColor,current,boundary;
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glColor3f(d, e, f);
}
void init()
{
	glClearColor(1.0, 1.0, 1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLint x, GLint y,Color setColor)
{
	
	setDrawingColor(setColor.r, setColor.g, setColor.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void s(unsigned int x[][640],int steps,Color setColor)
{
	unsigned int window_RGBData[480][640];
	for (int i = 0; i < steps; i++)
	{
		window_RGBData[0][i] = x[0][1];
		window_RGBData[0][i + 1] = x[0][i + 1];
	}
	glColor3f(setColor.r,setColor.g,setColor.b);
	glDrawPixels(1, 1, GL_RGB, GL_FLOAT, window_RGBData);
}
void setAxes()
{
	setDrawingColor(0.0,1.0,1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450,250);
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
void DDA(Point a,Point b)
{
	//unsigned int x[480][640];
	Color myLineColor = { 1.0, 0.0, 0.0 };
	GLint x1 = a.x;
	GLint y1 = a.y;
	GLint x2 = b.x;
	GLint y2 = b.y;
	setPixel(x1, y1, myLineColor);
	setPixel(x2, y2, myLineColor);
	GLint dx = x2 - x1;
	GLint dy = y2 - y1;
	GLint steps=abs(dy);//ASSUMED
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	GLfloat incrx = dx / float(steps);
	GLfloat incry = dy / float(steps);
	for (GLint i = 0; i < steps; i++)
	{
		x1 = x1 + incrx;
		y1 = y1 + incry;
		//x[0][i] = x1;
		//x[0][i+1] = y1;
		setPixel(x1, y1, myLineColor);
	}
	//s(x, steps, myLineColor);
}
void drawSquare()
{
	Point a, b,c,d;
	a.x = a.y = 250;
	b.x = 300; b.y = 250;
	c.x = c.y = 300;
	d.x = 250; d.y = 300;
	DDA(a, b);
	DDA(b, c);
	DDA(c, d);
	DDA(d, a);
}
void boundaryFill(int x, int y,Color fill,Color boundary)
{
	//ct++;
	Color current;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &current);
	//cout << current.r << current.g << current.b<<"\n";
	//cout << boundary.r << boundary.g << boundary.b << "\n";
	if (boundary.r == current.r&&boundary.g != current.g&&boundary.b != current.b)	{
		setPixel(x, y, fill);
		boundaryFill(x + 1, y, fill, boundary);
		boundaryFill(x - 1, y, fill, boundary);
		boundaryFill(x, y + 1, fill, boundary);
		boundaryFill(x, y - 1, fill, boundary);
		//boundaryFill(x+1, y + 1, fill, boundary);
		//boundaryFill(x-1, y + 1, fill, boundary);
		//boundaryFill(x+1, y - 1, fill, boundary);
		//boundaryFill(x-1, y -1, fill, boundary);
	}
	//cout << ct << "\n";
}
void floodFill(int x,int y,Color fillColor,Color oldColor)
{
	//Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &current);
	//cout << "here floodfill in\n";
	//cout << current.r << current.g << current.b;
	if (current.r == oldColor.r&&current.g == oldColor.g&&current.b == oldColor.b){
		setPixel(x, y, fillColor);
		//glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &current);
		floodFill(x + 1, y, fillColor, oldColor);
		floodFill(x , y+1, fillColor, oldColor);
		floodFill(x - 1, y, fillColor, oldColor);
		floodFill(x , y-1, fillColor, oldColor);
	}
}
void draw_Square(int x,int y,Color drawColor)
{
	

	Point a, b, c, d;
	a.x = x - 20; a.y = y-20;
	b.x = x - 20; b.y = y+20;
	c.x = x+20; c.y = y + 20;
	d.x = x+20; d.y = y - 20;
	DDA(a, b);
	DDA(b, c);
	DDA(c, d);
	DDA(d, a);
}
void myMouse(int button, int state, int x, int y)
{
	
	//old = { .8, .5, 0.0 };
	//cout << x << y;
	/*if (button == GLUT_LEFT_BUTTON&&state == GLUT_DOWN){
		
		floodFill(275,275, fill1, old);
	}*/
	//if (button == GLUT_LEFT_BUTTON&&state == GLUT_DOWN)
	//{
		//draw_Square(x,y,fill1);
	//}
	//else if (button == GLUT_RIGHT_BUTTON&&state == GLUT_DOWN)
		//exit(0);

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setAxes();
	drawSquare();
	boundary = { 1.0, 0.0, 0.0 };
	fill1 = { 0.8, .5, 0.0 };
	boundaryFill(275, 275, fill1, boundary);
	glReadPixels(255, 255, 1, 1, GL_RGB, GL_FLOAT, &oldColor);
	fill1 = { 0.0, 0.0, 1.0 };
	floodFill(255, 255, fill1, oldColor);
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
	//glutMouseFunc(myMouse);
	glutMainLoop();
	return 0;
}