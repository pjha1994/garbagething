#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void setPixel(float xc,float yc,float x,float y)
{
glPointSize(3);
glBegin(GL_POINTS);
 glVertex2f(x,y);
glEnd();

glLineWidth(5);
glBegin(GL_LINES);
 glVertex2f(xc,yc);
 glVertex2f(x,y);
glEnd();

}

void drawball(float xCenter,float yCenter,int radius)
{
 int i;
 for(i=0;i<360;i++)
  setPixel(xCenter,yCenter,xCenter+(radius*cos((i*3.1459)/180)),yCenter+(radius*sin((i*3.1459)/180)));
}

void balloverball()
{
 int i,count;
 count=0;

while(1)
{
  
  for(i=0;i<=360;i++)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,0.0,0.0);
   drawball(0,0,100);
   glColor3f(0.0,0.0,1.0);
   drawball((150*cos((i*3.1459)/180)),(150*sin((i*3.1459)/180)),50);
   glFlush();
  }
 count++;
 if(count==2)
  exit(0);
}
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
 glMatrixMode(GL_PROJECTION);
 glFlush();
 balloverball();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
