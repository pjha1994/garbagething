#include<GL/glut.h>
//#include<stdio.h>
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
void init()
{
	float x, y, z;
	cout<<"ENTER DRAWING COLOR\n";
	cin >> x;
	cin >> y;
	cin >> z;
	cout << x << y << z;
	glClearColor(1.0, 1.0, 1.0,1.0);
	glColor3f(x, y, z);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	GLfloat vertices[3][3] = { { 0.0, 0.0, 0.0 }, { 250.0, 500.0, 0.0 }, { 500.0, 0.0, 0.0 } };
	GLfloat p[3] = {75.0,50.0,0.0};
	int j, k;
	rand();
	glBegin(GL_POINTS);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[1]);
	glVertex3fv(vertices[2]);
	for (k = 0; k<5000; k++)
	{
		j = rand() % 3;
		p[0] = (p[0] + vertices[j][0]) / 2;
		p[1] = (p[1] + vertices[j][1]) / 2;
		glVertex2fv(p);
	}
	glEnd();
	glFlush();
}
void display1()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(100.0, 200.0);
	glVertex2f(40.0, 56.0);
	glVertex2f(89.0, 50.0);
	glEnd();
	glFlush();
}
void main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	//glutInitWindowSize(500, 500);
	//glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL EXAMPLE 2");
	init();
	glutDisplayFunc(display1);
	glutMainLoop();
}