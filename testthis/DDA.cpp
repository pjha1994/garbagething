#include<GL/glut.h>
#include<iostream>
GLint x_1, y_1, x_2, y_2,offset=250;
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
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
	setDrawingColor(1.0, 1.0,0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	setDrawingColor(1.0,0.0,0.0);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	setDrawingColor(1.0,1.0,0.0);
	glVertex2i(450, 250);
	setDrawingColor(0.0,1.0,1.0);
	glVertex2i(50, 250);
	glVertex2i(250, 250);
	setDrawingColor(0.0,0.0,1.0);
	glVertex2i(250, 50);
	glEnd();
	glFlush();
}
void setPixel(GLint x,GLint y)
{
	setDrawingColor(0.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(offset+x,offset+y);
	glEnd();
	glFlush();
}
void DDA(GLint x_1,GLint y_1,GLint x_2,GLint y_2)
{
	GLint dx = x_2 - x_1;
	GLint dy = y_2 - y_1;
	GLint steps;
	GLint x = x_1;
	GLint y = y_1;
	setPixel(x, y);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	setPixel(x, y);
	GLint incrx = dx / (steps);
	GLint incry = dy / (steps);
	for (GLint i = x_1; i <= x_2; i++)
	{
		x = x + incrx;
		y = y + incry;
		setPixel(int(x+0.5), int(y+0.5));
	}
}
void bresenham(GLint x_1, GLint y_1, GLint x_2, GLint y_2)
{



}
void display()
{
	setAxes();
	if (x_1 < x_2)
		DDA(x_1, y_1, x_2, y_2);
	else
		DDA(x_2, y_2, x_1, y_1);
}
int main(int argc, char **argv)
{
	std::cout << "Enter the two coordinates\n";
	std::cin >> x_1 >> y_1 >> x_2 >> y_2;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("hola");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}