//Parametric spiral 

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int a,b,c,d;

void drawspiral(int x,int y,int turns,int factor)
{
float xp,yp,i,t;
for(i=0;i<turns;i++)
{
t=(3.1459*i)/180;
xp=x+factor*t*cos(t);
yp=y+factor*t*sin(t);
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
gluOrtho2D(-1000,1000,-1000,1000);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glFlush();

a=0; b=0; c=4;//c=turns 
d=20;//factor

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
 glutCreateWindow (" Parametric spiral ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
