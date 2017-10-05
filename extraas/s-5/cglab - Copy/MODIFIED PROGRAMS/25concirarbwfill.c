//area b/w concentric circle filling

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int cx,cy,rad1,rad2;

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

cx=0;cy=0;rad1=800;rad2=400;

drawcircle(cx,cy);
glLineWidth(1);
drawaxes();
}

void drawcircle(int xc,int yc)
{
float xp,yp,xp1,yp1,i;

for(i=0;i<360;i++)
{
glEnable(GL_LINE_SMOOTH);
glEnable(GL_POINT_SMOOTH);
xp=xc+rad1*cos(3.14*(i/180));
yp=yc+rad1*sin(3.14*(i/180));

xp1=xc+rad2*cos(3.14*(i/180));
yp1=yc+rad2*sin(3.14*(i/180));

glLineWidth(5);
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
	glVertex2f(xc,yc);
	glVertex2f(xp,yp);
glEnd();

glColor3f(0.0,0.0,1.0);
glPointSize(5);
glBegin(GL_POINTS);  
 glVertex2f(xp,yp);
glEnd();

glLineWidth(10);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
	glVertex2f(xc,yc);
	glVertex2f(xp1,yp1);
glEnd();

glColor3f(0.0,0.0,1.0);
glPointSize(5);
glBegin(GL_POINTS);  
 glVertex2f(xp1,yp1);
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
