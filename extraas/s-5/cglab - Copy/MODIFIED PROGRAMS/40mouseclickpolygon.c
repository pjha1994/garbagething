#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct points
{
 int x;
 int y;
}p[100];


int n,count;

void getdata()
{
 int i;
 printf("Enter the number of vertices of the polygon: ");
 scanf("%d",&n);
}


void drawpolygonline(int xa,int ya,int xb,int yb)
{
 int i;
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_LINES);
    glVertex2f(xa,ya);
    glVertex2f(xb,yb);
 glEnd();
 glFlush();
}

void mouseclick(int button,int state,int x,int y)
{
if(count<n)
{
 switch (button) 
 {
  case GLUT_LEFT_BUTTON:
       if (state == GLUT_DOWN)
       { 
        p[count].x=x;
        p[count].y=500-y;
        printf("x=%d y=%d\n",p[count].x,p[count].y);
        if(count>0)        
           drawpolygonline(p[count-1].x,p[count-1].y,p[count].x,p[count].y);
        count++;
       }
  break;
 }
}
else
 {
 drawpolygonline(p[count-1].x,p[count-1].y,p[0].x,p[0].y);
 printf("recieved all inputs\n");
 }
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
 glMatrixMode(GL_PROJECTION);
 glFlush();
}

int main(int argc, char** argv)
{
 count=0;
 getdata();
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" ");
 init ();
 glutDisplayFunc(display);
 glutMouseFunc(mouseclick);
 glutMainLoop(); 
 return 0;
}
