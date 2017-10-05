//scrolling letters

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void drawfont()
{
glColor3f(1.0,1.0,1.0);
glEnable(GL_LINE_SMOOTH);
glEnable(GL_POINT_SMOOTH);
glLineWidth(20);
glPointSize(5);
//C
 drawarc(100,100,180,360);
 drawarc(100,200,0,180);
 drawline(50,100,50,200);
//O
 drawarc(250,100,180,360);
 drawarc(250,200,0,180);
 drawline(200,100,200,200);
 drawline(300,100,300,200);
//M
 drawline(350,50,350,250);
 drawline(450,50,450,250);
 drawline(400,150,350,250);
 drawline(400,150,450,250);
//P
 drawline(500,50,500,250);
 drawline(500,250,550,250);
 drawline(500,150,550,150);
 drawarc(550,200,-90,90);
//U
 drawline(650,100,650,250);
 drawline(750,100,750,250);
 drawarc(700,100,180,360);
//T
 drawline(800,250,900,250);
 drawline(850,50,850,250);
//E
 drawline(950,250,1050,250);
 drawline(950,50,1050,50);
 drawline(950,150,1050,150);
 drawline(950,50,950,250);
//R
 drawline(1100,50,1100,250);
 drawline(1100,250,1150,250);
 drawline(1100,150,1150,150);
 drawarc(1150,200,-90,90);
 drawline(1150,150,1200,50);
glFlush();
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
