#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
#include<math.h>
using namespace std;
void init()
{
	glClearColor(255.0, 250.0, 250.0, 1.0);
	glColor3f(0.0,255.0,255.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	GLfloat x = 250.0, y = 250.0, max_x = 350.0, max_b = 350.0;
	glBegin(GL_LINE_STRIP);
	glVertex2f(250.0, 250.0);
	glVertex2f(450.0, 250.0);
	glVertex2f(250.0, 250.0);
	glVertex2f(250.0, 450.0);
	glVertex2f(250.0, 250.0);
	glVertex2f(250.0, 50.0);
	glVertex2f(250.0, 250.0);
	glVertex2f(50.0, 250.0);
	glEnd();
	glFlush();
	glBegin(GL_POINTS);
	for (GLfloat i = x; i <= max_x; i++)
	{       if(!(100 * 100 - (i - 250)*(i - 250))<0)
                {
		GLfloat m = sqrt(100 * 100 - (i - 250)*(i - 250));
                glVertex2f(i,250.0+m);
		glVertex2f(i, 250-m);
                }
	}
	for (GLfloat i = 50.0; i <= 250.0; i++)
	{     if(!(100 * 100 - (i - 250)*(i - 250))<0)
		{GLfloat m = sqrt(100 * 100 - (i - 250)*(i - 250));
		glVertex2f(i, 250.0+m);
		glVertex2f(i, 250.0-m);
                }
	}
	/*HWND hwnd = FindWindow(NULL, "Pixel In Console?"); // Get the HWND
	HDC hdc = GetDC(hwnd);
	COLORREF color = RGB(255, 255, 0);
	SetPixel(hdc, 200, 102, color);*/
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("OPENGL EXAMPLE 1");
	//init();
	glutDisplayFunc(display);
	glutMainLoop();
        return 0;
}
