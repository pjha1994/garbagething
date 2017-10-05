//Parametric ellipse

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

cx=0;cy=0;twoa=800;twob=400;

glColor3f(0.0,1.0,0.0);
glBegin(GL_POINTS);  
   drawellipse(cx,cy,twoa,twob);
glEnd();

drawaxes();
glutSwapBuffers();
}

void drawellipse(int xc,int yc,int a,int b)
{
a=a/2;
b=b/2;
float xp,yp,i;
for(i=0;i<360;i++)
{
xp=xc+a*cos(3.14*(i/180));
yp=yc+b*sin(3.14*(i/180));
glVertex2f(xp,yp);
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
