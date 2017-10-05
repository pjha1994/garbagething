#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
GLfloat cor_1, cor_2, cor_3, cor_4;
void setDrawingColor(GLfloat d=255.0,GLfloat e=255.0,GLfloat f=255.0 )
{
	glClearColor(0.0, 0.0,0.0, 1.0);
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
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 255.0, 255.0);
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
}
void DDA(GLfloat cor_1, GLfloat cor_2, GLfloat cor_3, GLfloat cor_4)
{
	GLfloat offset = 250.0;
	GLfloat x = cor_1+offset, y = cor_2+offset, a = cor_3+offset, b = cor_4+offset;
	GLfloat dx = a - x;
	GLfloat dy = b - y;
	
	if (dx != 0 && dy != 0)
	{
		GLfloat m = dy /(GLfloat) dx;
		{   setPixel(x, y);
			if (m <= 1 && m > 0)
			{
				GLfloat j = y;
				for (GLfloat i = x+1; (i <= a) && (j <= b); i++)
				{
					j = j + m;
					setPixel(i,j);
					cout << "  x = " << i-offset << "   y = " << j-offset<<"\n";
				}
			}
			else if (m > 1)
			{
				GLfloat j = x;
				GLfloat t = 1.0;
				for (GLfloat i = y+1; (i <= b) && (j <= a); i++)
				{
					j = j + t/m;
					setPixel(j,i);
					cout << "  x = " << j-offset << "   y = " << i-offset << "\n";
				}
			}
		   
			else if (m < 0)
			{
				GLfloat trial = -m;
				cout << trial;
				if (trial<1)
				{

					cout << "HERE\n";
					GLfloat j = y;
					for (GLfloat i = x + 1; (i <= a)&&(j<=b); i++)
					{
						
						j = j + m;
						setPixel(i,j);
						cout << "  x = " << i - offset << "   y = " << j - offset << "\n";
					}
				}
				else
				{
					GLfloat j = x;
					for (GLfloat i = y - 1; (i <= b) && (j <= a); i--)
					{
						j = j - (GLfloat)1/ m;
						setPixel(j, i);
						cout << "  x = " << j - offset << "   y = " << i - offset << "\n";
					}
				}
			}
		}
	}
	else
	{
		exit(0);
	}
}
void display()
{
setAxes();
if (cor_1 < cor_3)
	DDA(cor_1, cor_2, cor_3, cor_4);
else
    DDA(cor_3,cor_4,cor_1,cor_2);
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> cor_1 >> cor_2 >> cor_3 >> cor_4;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
