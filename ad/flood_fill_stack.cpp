#include<iostream>
#include<GL/glut.h>
struct Point{
	GLint x;
	GLint y;
}arr[100000];
struct Color{
	GLfloat r, g, b;
};
int top = -1;
void push(GLint x, GLint y)
{
	if (top > 100000)
		exit(0);
	    top++;
		arr[top].x = x;
		arr[top].y = y;
}
void pop(GLint *x,GLint *y)
{
	if (top <= -1)
		exit(0);
	*x = arr[top].x;
	*y = arr[top].y;
	top--;
}
void init()
{
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
}
void draw_poly(Point a,Point b,Point c,Point d)
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(a.x, a.y);
	glVertex2i(b.x, b.y);
	glVertex2i(b.x, b.y);
	glVertex2i(c.x, c.y);
	glVertex2i(c.x, c.y);
	glVertex2i(d.x, d.y);
	glVertex2i(d.x, d.y);
	glVertex2i(a.x, a.y);
	glEnd();
	glFlush();
}
void setPixel(GLint x, GLint y, Color color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void boundaryFill(GLint x, GLint y, Color boundary, Color fillColor)
{
	Color current;
	setPixel(x, y, fillColor);
	push(x, y);
	while (top >= 0)
	{
		pop(&x, &y);
		glReadPixels(x + 1, y, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r == boundary.r&&current.g == boundary.g&&current.b == boundary.b){

			setPixel(x + 1, y, fillColor); 
			//glRasterPos2d(x+1, y);
			//glDrawPixels(1, 1, GL_RGB, GL_FLOAT, &fillColor); 
			push(x + 1, y);
		}

		glReadPixels(x - 1, y, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r == boundary.r&&current.g == boundary.g&&current.b == boundary.b){
			setPixel(x - 1, y, fillColor); 
			//glRasterPos2d(x - 1, y);
			//glDrawPixels(1, 1, GL_RGB, GL_FLOAT, &fillColor); 
			push(x - 1, y);
		}

		glReadPixels(x, y + 1, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r == boundary.r&&current.g == boundary.g&&current.b == boundary.b){
			setPixel(x, y + 1, fillColor);
			//glRasterPos2d(x , y+1);
			//glDrawPixels(1, 1, GL_RGB, GL_FLOAT, &fillColor); 
			push(x, y + 1);
		}

		glReadPixels(x, y - 1, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r == boundary.r&&current.g == boundary.g&&current.b == boundary.b){
			setPixel(x, y - 1, fillColor); 
			//glRasterPos2d(x , y-1);
			//glDrawPixels(1, 1, GL_RGB, GL_FLOAT, &fillColor); 
			push(x, y - 1);
		}
		glFlush();
	}
}
void floodFill(GLint x, GLint y, Color oldColor, Color newColor)
{
	Color current;
	setPixel(x, y, newColor);
	push(x, y);
	while (top>=0)
	{
		pop(&x, &y);
		glReadPixels(x+1, y, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r==oldColor.r&&current.g==oldColor.g&&current.b==oldColor.b){
			setPixel(x+1, y,newColor); push(x+1, y);
		}
		
		glReadPixels(x - 1, y, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r == oldColor.r&&current.g == oldColor.g&&current.b == oldColor.b){
			setPixel(x - 1, y, newColor); push(x - 1, y);
		}
		
		glReadPixels(x , y+1, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r == oldColor.r&&current.g == oldColor.g&&current.b == oldColor.b){
			setPixel(x , y+1, newColor); push(x , y+1);
		}
		
		glReadPixels(x , y-1, 1, 1, GL_RGB, GL_FLOAT, &current);
		if (current.r == oldColor.r&&current.g == oldColor.g&&current.b == oldColor.b){
			setPixel(x , y-1, newColor); push(x , y-1);
		}
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	Point a, b, c, d;
	a.x = a.y = 10;
	b.x = 500-200; b.y = 10;
	c.x = 500-200; c.y = 500-200;
	d.x = 10; d.y = 500-200;
	draw_poly(a,b,c,d);
	Color oldColor, newColor = {0.0,1.0,0.0};
	//glRasterPos2d(a.x, a.y);
	//glDrawPixels(100, 10, GL_RGB, GL_FLOAT, &newColor);
	
	glReadPixels(11, 11, 1, 1, GL_RGB, GL_FLOAT, &oldColor);
	floodFill(11, 11, oldColor, newColor);
	Color boundary, fillColor = {0.0,1.0,1.0};
	glReadPixels(10, 10, 1, 1, GL_RGB, GL_FLOAT, &boundary);
	boundaryFill(11, 11, boundary, fillColor);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("hola");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}