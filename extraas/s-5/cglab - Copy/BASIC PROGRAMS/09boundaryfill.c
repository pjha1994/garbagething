#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct das
{
 int x;
 int y;
} p[100000];

int top;
float boundarycolor[3],fillcolor[3];

void push(int x,int y)
{
 top++;
 if(top==100000)
   exit(0);
 p[top].x=x;
 p[top].y=y;
}

void pop(int *x,int *y)
{
 *x=p[top].x; *y=p[top].y;
 top--;
}

setPixel(int x,int y)
{
 glColor3fv(fillcolor);
 glPointSize(10);
 glBegin(GL_POINTS);
  glVertex2f(x,y);
 glEnd();
 glFlush();
}

void boundaryfill(int x,int y)
{
 int xc,yc;
 push(x,y);
 float currentcolor[3];
 setPixel(x,y);

while(top>0)
 {
 pop(&xc,&yc);
 glReadPixels(xc+10,yc,1.0,1.0,GL_RGB,GL_FLOAT,currentcolor);
 if(currentcolor[0]!=boundarycolor[0] && currentcolor[1]!=boundarycolor[1] && currentcolor[2]!=boundarycolor[2])
 { setPixel(xc+10,yc); push(xc+10,yc); }

 glReadPixels(xc-10,yc,1.0,1.0,GL_RGB,GL_FLOAT,currentcolor);
 if(currentcolor[0]!=boundarycolor[0] && currentcolor[1]!=boundarycolor[1] && currentcolor[2]!=boundarycolor[2])
 { setPixel(xc-10,yc); push(xc-10,yc); }

 glReadPixels(xc,yc+10,1.0,1.0,GL_RGB,GL_FLOAT,currentcolor);
  if(currentcolor[0]!=boundarycolor[0] && currentcolor[1]!=boundarycolor[1] && currentcolor[2]!=boundarycolor[2])
 { setPixel(xc,yc+10); push(xc,yc+10); }

 glReadPixels(xc,yc-10,1.0,1.0,GL_RGB,GL_FLOAT,currentcolor);
  if(currentcolor[0]!=boundarycolor[0] && currentcolor[1]!=boundarycolor[1] && currentcolor[2]!=boundarycolor[2])
 { setPixel(xc,yc-10); push(xc,yc-10); }
}
}



void drawPolygon()
{
 glColor3fv(boundarycolor);
 glLineWidth(20);
 glBegin(GL_LINES);
  glVertex2f(100,100);
  glVertex2f(100,400);
  glVertex2f(100,400);
  glVertex2f(400,400);
  glVertex2f(400,400);
  glVertex2f(400,100);
  glVertex2f(400,100);
  glVertex2f(100,100);
 glEnd();
glFlush(); 
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(0,500,0,500);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
boundarycolor[0]=1.0; boundarycolor[1]=1.0; boundarycolor[2]=1.0; 
drawPolygon();
fillcolor[0]=0.0; fillcolor[1]=0.0; fillcolor[2]=1.0;
boundaryfill(300,300);
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
