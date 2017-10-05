#include<GL/glut.h>
#include<stdio.h>

int count;

void setPixel(int x,int y,int xc,int yc,int flag)
{
 glPointSize(3);
 glBegin(GL_POINTS);
  glVertex2f(x,y);
 glEnd();

 if(flag==1)
 {
  glLineWidth(5);
  glBegin(GL_LINES);
   glVertex2f(xc,yc);
  glVertex2f(x,y);
 glEnd();
 }
}


void drawcircle(int xcenter,int ycenter,int radius,int fillflag)
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

 setPixel(xcenter+x,ycenter+y,xcenter,ycenter,fillflag); 
 setPixel(xcenter+x,ycenter-y,xcenter,ycenter,fillflag);
 setPixel(xcenter-x,ycenter+y,xcenter,ycenter,fillflag);
 setPixel(xcenter-x,ycenter-y,xcenter,ycenter,fillflag);
 setPixel(xcenter+y,ycenter+x,xcenter,ycenter,fillflag);
 setPixel(xcenter+y,ycenter-x,xcenter,ycenter,fillflag);
 setPixel(xcenter-y,ycenter+x,xcenter,ycenter,fillflag);
 setPixel(xcenter-y,ycenter-x,xcenter,ycenter,fillflag);
 }
}


void trafficlight()
{
int i,j,k,m;
for(m=0;m<1000;m++)
{
 if(count==10)
  exit(0);
 else if(count%3==0)
 {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  drawcircle(100,75,50,0);
  glColor3f(1.0,1.0,0.0);
  drawcircle(100,200,50,0);
  glColor3f(0.0,1.0,0.0);
  drawcircle(100,325,50,1);
  glFlush();
  count++;
 }
 else if(count%3==1)
 {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  drawcircle(100,75,50,1);
  glColor3f(1.0,1.0,0.0);
  drawcircle(100,200,50,0);
  glColor3f(0.0,1.0,0.0);
  drawcircle(100,325,50,0);
  glFlush();
  count++;
 }
 else if(count%3==2)
 {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  drawcircle(100,75,50,0);
  glColor3f(1.0,1.0,0.0);
  drawcircle(100,200,50,1);
  glColor3f(0.0,1.0,0.0);
  drawcircle(100,325,50,0);
  glFlush();
  count++;
 }
 for(i=0;i<100000;i++)
  for(j=0;j<10000;j++)
   k=0;
}
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(0,200,0,400);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glFlush();
trafficlight();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (200,400);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
