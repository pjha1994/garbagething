//Bresenhamline circle filling

#include<GL/glut.h>
#include<stdio.h>

int xc,yc,rad,n;

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
bresenhamcircle(xc,yc,rad);
drawaxes();
glutSwapBuffers();
}

void bresenhamcircle(int xcenter,int ycenter,int radius)
{
int p=3/2-radius;
int x=0, y=radius;

while(x<=y)
{
 x++;
 if(p<0)
  p+=2*x+3;
 else
 {
  y--; 
  p+=2*(x-y)+5;
 }

setPixel(xcenter+x,ycenter+y); 
setPixel(xcenter+x,ycenter-y);
setPixel(xcenter-x,ycenter+y);
setPixel(xcenter-x,ycenter-y);
setPixel(xcenter+y,ycenter+x);
setPixel(xcenter+y,ycenter-x);
setPixel(xcenter-y,ycenter+x);
setPixel(xcenter-y,ycenter-x);
}

}

void drawaxes()
{
glLineWidth(1);
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
glPointSize(3);
glColor3f(1.0,1.0,0.0);
glBegin(GL_POINTS);
 glVertex2f(x,y);
glEnd();

glLineWidth(5);
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
 glVertex2f(xc,yc);
 glVertex2f(x,y);
glEnd();

}

int main(int argc, char** argv)
{
 printf("Enter the circle center (x,y)\n");
 scanf("%d%d",&xc,&yc);
 printf("Enter the circle radius (r)\n");
 scanf("%d",&rad);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow (" Bresenham circle ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
