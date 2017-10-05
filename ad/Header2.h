



//Parametric Circle


#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define offset 250
using namespace std;
GLfloat center_x, center_y, radius;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLfloat x, GLfloat y)
{
	setDrawingColor(0.0, 255.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(offset + x, offset + y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 255.0, 255.0);
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
void param()
{
	for (GLfloat i = 0; i <= 360; i = i + 1)
	{
		GLfloat a = center_x + radius*GLfloat(cos(3.14*(i / (GLfloat)180)));
		GLfloat b = center_y + radius*GLfloat(sin(3.14*(i / (GLfloat)180)));
		cout << "a =" << a << " b = " << b << "\n";
		//setDrawingColor(0.0, 255.0, 0.0);
		//glClear(GL_COLOR_BUFFER_BIT);
		setPixel(a, b);
		/*GLfloat c = center_x + radius*GLfloat(cos(3.14*((i +90)/ (GLfloat)180)));
		GLfloat d = center_y + radius*GLfloat(sin(3.14*((i +90)/ (GLfloat)180)));
		setDrawingColor(255, 0, 255);
		setPixel(c, d);
		GLfloat e = center_x + radius*GLfloat(cos(3.14*((i + 180) / (GLfloat)180)));
		GLfloat f = center_y + radius*GLfloat(sin(3.14*((i+180) / (GLfloat)180)));
		setDrawingColor(255, 0, 0);
		setPixel(e, f);
		GLfloat g = center_x + radius*GLfloat(cos(3.14*((i + 270) / (GLfloat)180)));
		GLfloat h = center_y + radius*GLfloat(sin(3.14*((i + 270) / (GLfloat)180)));
		setDrawingColor(0, 0, 255.0);
		setPixel(g, h);*/
	}
}
void display()
{
	setAxes();
	param();
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> center_x >> center_y >> radius;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

