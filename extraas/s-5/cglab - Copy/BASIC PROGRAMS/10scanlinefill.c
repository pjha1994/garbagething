//Bresenhamline circle

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int a,b,c,d,flag;

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(-1000,1000,-1000,1000);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);

drawaxes();
glutSwapBuffers();
}



void drawaxes()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
	glVertex2i(0,-1000);
	glVertex2i(0,1000);
	glVertex2i(-1000,0);
	glVertex2i(1000,0);
glEnd();
}

void setPixel(int x,int y)
{
glBegin(GL_POINTS);
 glVertex2f(x,y);
glEnd();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" window");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
