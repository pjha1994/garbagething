#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
static int n=0;
void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,400.0,0.0,400.0);
}

int round1(long number)
{
 return(number>0)?(int)(number+0.5):(int)(number+0.5);
}

 void setpixel(int x,int y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}
void dda(int x1,int y1,int x2,int y2)
{
  int dy=y2-y1;
  int dx=x2-x1;
  int steps,i;
  float xinc,yinc,x=x1,y=y1;
  //glClear(GL_CLEAR_BUFFER_BIT);
  if(abs(dx)>abs(dy)){
  steps=abs(dx);

}else
{
 steps=abs(dy);
}
 xinc=(float)dx/(float)steps;
 yinc=(float)dy/(float)steps;
 setpixel(round1(x),round1(y));
 for(i=0;i<steps;i++){
  x+=xinc;
  y+=yinc;
  setpixel(round1(x),round1(y));

}
  glFlush();


}

void serpensiky(int x0,int y0,int x1,int y1,int x2,int y2,int n)
{ n++;
 if(n>5)
	return;

 glColor3f(0.0,0.0,0.0);
 dda(x0,y0,x1,y1); 
 glColor3f(0.0,0.0,0.0);
 dda(x0,y0,x2,y2);
 glColor3f(0.0,0.0,0.0);
 dda(x1,y1,x2,y2);
 int mx0=(x0+x1)/2,my0=(y0+y1)/2,mx1=(x1+x2)/2,my1=(y1+y2)/2,mx2=(x0+x2)/2,my2=(y0+y2)/2;
 serpensiky(mx0,my0,mx1,my1,mx2,my2,n);
 //glColor3f(1.0,1.0,0.0);
 serpensiky(x1,y1,mx0,my0,mx1,my1,n);
//glColor3f(1.0,0.0,0.0);
 serpensiky(x2,y2,mx1,my1,mx2,my2,n);
glColor3f(0.0,0.0,1.0);
 serpensiky(x0,y0,mx0,my0,mx2,my2,n);


}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
serpensiky(10,10,390,10,190,390,0);
}

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(400,400);
  glutCreateWindow("serpensiky");
  init();

  glutDisplayFunc(display);
  glutMainLoop();
 

}


