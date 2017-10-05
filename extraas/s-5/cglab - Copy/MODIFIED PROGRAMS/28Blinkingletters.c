//Blinking letters

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float r,g,b;
int l;

void randomcolor()
{
l++;
if(l%3==0)
 r=g=b=1.0;
else if(l%3==1)
 {r=1.0;g=b=0.0;}
else if(l%3==2)
 {b=1.0;r=g=0.0;}
}

void drawfont()
{
int i,j,k,t;
for(i=-1300;i<2600;i++)
{ 
for(j=0;j<10000;j++)
  for(k=0;k<10;k++)
	t=0;
randomcolor();
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(r,g,b);
glEnable(GL_LINE_SMOOTH);
glEnable(GL_POINT_SMOOTH);
glLineWidth(20);
glPointSize(5);
//C
 drawarc(100+i,100,180,360);
 drawarc(100+i,200,0,180);
 drawline(50+i,100,50+i,200);
//O
 drawarc(250+i,100,180,360);
 drawarc(250+i,200,0,180);
 drawline(200+i,100,200+i,200);
 drawline(300+i,100,300+i,200);
//M
 drawline(350+i,50,350+i,250);
 drawline(450+i,50,450+i,250);
 drawline(400+i,150,350+i,250);
 drawline(400+i,150,450+i,250);
//P
 drawline(500+i,50,500+i,250);
 drawline(500+i,250,550+i,250);
 drawline(500+i,150,550+i,150);
 drawarc(550+i,200,-90,90);
//U
 drawline(650+i,100,650+i,250);
 drawline(750+i,100,750+i,250);
 drawarc(700+i,100,180,360);
//T
 drawline(800+i,250,900+i,250);
 drawline(850+i,50,850+i,250);
//E
 drawline(950+i,250,1050+i,250);
 drawline(950+i,50,1050+i,50);
 drawline(950+i,150,1050+i,150);
 drawline(950+i,50,950+i,250);
//R
 drawline(1100+i,50,1100+i,250);
 drawline(1100+i,250,1150+i,250);
 drawline(1100+i,150,1150+i,150);
 drawarc(1150+i,200,-90,90);
 drawline(1150+i,150,1200+i,50);
glFlush();
}
}


void drawline(int x1,int y1,int x2,int y2)
{
  glBegin(GL_LINES);
   glVertex2f(x1,y1);
   glVertex2f(x2,y2);
  glEnd();
}

void drawarc(int x,int y,int start,int end)
{
 float xp,yp,i;
 for(i=start;i<=end;i++)
 {
  xp=x+50*cos(3.14*(i/180));
  yp=y+50*sin(3.14*(i/180));
  glBegin(GL_POINTS);
   glVertex2f(xp,yp);
  glEnd();
 }
}

void init()
{
 glClearColor(0.0,0.0,0.0,0.0);
 glLoadIdentity();
 gluOrtho2D(0,1300,0,300);
}

void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glFlush();
 drawfont();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (650,150);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
