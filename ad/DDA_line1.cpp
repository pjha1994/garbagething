#include<GL/glut.h>
#include<iostream>
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 205.0, 255.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	GLfloat i, j,k;
	GLfloat x, y;
	GLfloat a, b;
	GLfloat m;
	std::cin >> x >> y;
	std::cin >> a >> b;
	//GLfloat x = 230,y=250;
	//GLfloat a = 250, b = 300;
	if (a - x != 0){
		GLfloat m = (b - y) / (GLfloat)(a - x);
		glBegin(GL_POINTS);
		glVertex2d(x, y	);
		glVertex2d(a, b);
		if (m <= 1 && m > 0)
		{
			i = x;
			k = y;
			for (; i < a; i++)
			{
				k = k + m;
				glVertex2f(i, k);
			}
		}
		else
		{
			i = x;
			k = y;
			for (; k < b; k++)
			{
				i = i + (1.0 / m);
				glVertex2f(i, k);
			}
		}
		glEnd();
		glFlush();
	}
}
void main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}