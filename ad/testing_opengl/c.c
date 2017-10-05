//Primitives

#include<glut.h>
#include<stdio.h>
void drawpolygon();
void drawtriangle();
void drawline();
void drawpoint();
void display();
void init()
{
glClearColor(0.0,0.0,1.0,0.0);
glLoadIdentity();
gluOrtho2D(0,500,0,500);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
drawpoint();
drawline();
//drawtriangle();
drawpolygon();
glFlush();
}

void drawpoint()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_POINTS);
	glVertex2f(100,100);
	glVertex2f(100,200);
	glVertex2f(100,300);
	glVertex2f(100,400);
glEnd();
}

void drawline()
{
glColor3f(1.0,1.0,0.0);
glBegin(GL_LINES);
	glVertex2f(110,183);
	glVertex2f(200,150);
	glVertex2f(300,400);
	glVertex2f(400,400);
glEnd();
}

void drawtriangle()
{
glColor3f(1.0,0.0,0.0);
glBegin(GL_TRIANGLES);
	glVertex2f(125,150);
	glVertex2f(200,250);
	glVertex2f(300,270);
glEnd();
}	

void drawpolygon()
{
glColor3f(0.0,1.0,1.0);
glBegin(GL_POLYGON);
	glVertex2f(300,150);
	glVertex2f(400,250);
	glVertex2f(500,270);
	glVertex2f(300,110);
glEnd();
}


int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow (" Primitives ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}