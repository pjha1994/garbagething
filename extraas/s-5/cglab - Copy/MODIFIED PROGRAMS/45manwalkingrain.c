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

drawline(int xa,int ya,int xb,int yb)
{
 glLineWidth(1.0);
 glBegin(GL_LINES);
  glVertex2f(xa,ya);
  glVertex2f(xb,yb);
 glEnd();
}

void drawcircle(int start,int end,int xCenter,int yCenter,int radius)
{
 int i;
 for(i=start;i<end;i++)
  setPixel(xCenter,yCenter,xCenter+(radius*cos((i*3.1459)/180)),yCenter+(radius*sin((i*3.1459)/180)));
}


void delay()
{
int i,j,k;
 for(i=0;i<1000;i++)
  for(j=0;j<10;j++)
    glClear(GL_COLOR_BUFFER_BIT);
}

void manwalkingrain()
{
 int i,count,n,j,k;
 count=0; n=0;

while(1)
{
  for(i=0;i<=1200;i++)
  {
    glClear(GL_COLOR_BUFFER_BIT);
    //rain
    for(k=0;k<1100;k+=100)
    {
     glColor3f(0.0,0.0,1.0);
     drawline(50+k,700,50+k,650) ;   
     drawline(50+k,600,50+k,550) ; 
     drawline(50+k,500,50+k,450) ; 
     drawline(50+k,400,50+k,350) ; 
     drawline(50+k,300,50+k,250) ; 
     drawline(50+k,200,50+k,150) ; 
    }
    //man
    glColor3f(1.0,0.5,0.0);
    drawcircle(0,360,50+i,275,25);
    glColor3f(0.5,0.5,0.5);
    drawline(50+i,250,50+i,50);
    drawline(50+i,150,100+i,50);
    drawline(50+i,200,100+i,225);
    //umberella
    glColor3f(1.0,0.0,0.0);
    drawline(100+i,225,100+i,325);
    drawcircle(0,180,100+i,325,75);
 
    glFlush();
    delay();
    i+=50;
    

    //rain
    for(k=0;k<1100;k+=100)
    {
     glColor3f(0.0,0.0,1.0);
     drawline(100+k,650,100+k,600) ; 
     drawline(100+k,550,100+k,500) ; 
     drawline(100+k,450,100+k,400) ;  
     drawline(100+k,350,100+k,300) ; 
     drawline(100+k,250,100+k,200) ; 
     drawline(100+k,150,100+k,100) ;    
    }
    //man2
    glColor3f(1.0,0.5,0.0);
    drawcircle(0,360,50+i,275,25);
    glColor3f(0.5,0.5,0.5);
    drawline(50+i,250,50+i,50);
    drawline(50+i,200,100+i,225);
    //umberella
    glColor3f(1.0,0.0,0.0);
    drawline(100+i,225,100+i,325);
    drawcircle(0,180,100+i,325,75);

    glFlush();
    delay();  
  }
 count++;
 if(count==1)
  exit(0);
}
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(0,1200,0,800);
}

void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glFlush();
 manwalkingrain();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (600, 400);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
