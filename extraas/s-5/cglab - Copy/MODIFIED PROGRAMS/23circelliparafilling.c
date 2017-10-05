//filling circle/ellipse parametric method

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int cx,cy,twoa,twob;

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
glFlush();

cx=0;cy=0;twoa=800;twob=400;

drawellipse(cx,cy,twoa,twob);
glLineWidth(1);
drawaxes();
}

void drawellipse(int xc,int yc,int a,int b)
{
a=a/2;
b=b/2;
float xp,yp,i;
glColor3f(0.0,1.0,0.0);
for(i=0;i<360;i++)
{
glColor3f(0.0,1.0,0.0);
xp=xc+a*cos(3.14*(i/180));
yp=yc+b*sin(3.14*(i/180));
glPointSize(3);
glBegin(GL_POINTS);  
 glVertex2f(xp,yp);
glEnd();
glLineWidth(5);
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
	glVertex2f(xc,yc);
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
glFlush();
}

void drawline(float xp,float yp)
{
glColor3f(0.0,1.0,1.0);
glBegin(GL_LINES);
	glVertex2f(cx,cy);
	glVertex2f(xp,yp);
glEnd();
glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" Parametric ellipse ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
