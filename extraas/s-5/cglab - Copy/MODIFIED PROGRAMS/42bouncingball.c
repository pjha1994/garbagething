#include<GL/glut.h>
#include<stdio.h>

void setPixel(int xc,int yc,int x,int y)
{
glPointSize(3);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
 glVertex2f(x,y);
glEnd();

glLineWidth(5);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
 glVertex2f(xc,yc);
 glVertex2f(x,y);
glEnd();

}

void drawball(int xcenter,int ycenter,int radius)
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

 setPixel(xcenter+x,ycenter+y,xcenter,ycenter); 
 setPixel(xcenter+x,ycenter-y,xcenter,ycenter);
 setPixel(xcenter-x,ycenter+y,xcenter,ycenter);
 setPixel(xcenter-x,ycenter-y,xcenter,ycenter);
 setPixel(xcenter+y,ycenter+x,xcenter,ycenter);
 setPixel(xcenter+y,ycenter-x,xcenter,ycenter);
 setPixel(xcenter-y,ycenter+x,xcenter,ycenter);
 setPixel(xcenter-y,ycenter-x,xcenter,ycenter);
 }
}

void drawline()
{
 glLineWidth(10);
 glColor3f(0.0,1.0,0.0);
 glBegin(GL_LINES);
  glVertex2f(0,50);
  glVertex2f(800,50);
 glEnd();
}


void bouncingball()
{
 int i,j,k,l,count;
 count=0;
while(1)
{
  for(i=0;i<=350;i+=15)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   drawline();
   drawball(400,100+i,50);
   glFlush();
  }
 
  for(i=0;i<350;i+=15)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   drawline();
   drawball(400,450-i,50);
   glFlush();
  }
 count++;
 if(count==3)
  exit(0);
}
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(0,800,0,500);
}

void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glFlush();
 bouncingball();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (800, 500);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
