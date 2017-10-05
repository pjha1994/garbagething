//Parametric spiral 

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int a,b,c,d;

void drawspiral(int x,int y,int turns,int r)
{
float xp,yp,i,t;
for(i=0;i<turns;i++)
{
t=(3.1459*i)/180;
xp=x+r*(t-sin(t));
yp=y+r*(1-cos(t));
glBegin(GL_POINTS);
 glVertex2f(xp,yp);
glEnd();
}
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

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glFlush();

a=0; b=0; c=4;//c=turns 
d=20;//radius

glColor3f(0.0,1.0,0.0);
drawspiral(a,b,c*360,d);
glFlush();
drawaxes();
glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" Parametric cycloid ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
