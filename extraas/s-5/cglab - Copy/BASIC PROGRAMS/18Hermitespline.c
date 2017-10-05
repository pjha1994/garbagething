//Hermite spline

#include<GL/glut.h>
#include<stdio.h>

//mathematical part
struct points
{
float x,y;
float slopex,slopey;
}p[10];

int ncpoints;

//blending functions
float h0(float u) 
{	return(2*u*u*u - 3*u*u + 1);	}

float h1(float u) 
{	return(-2*u*u*u+3*u*u);		}

float h2(float u) 
{	return (u*u*u - 2*u*u + u);	}

float h3(float u) 
{	return (u*u*u-u*u);		}


//curve calculation and drawing
void drawhermitespline()
{
 float x,y,u;
 int k;
 glEnable(GL_LINE_SMOOTH);
 glLineWidth(3);
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINE_STRIP); //plotting the curve
  for(k=0;k<ncpoints;k++)
  {
   for(u=0;u<1;u+=0.04)
   {
    x= h0(u)*p[k].x + h1(u)*p[k+1].x + h2(u)*p[k].slopex + h3(u)*p[k+1].slopex;
    y= h0(u)*p[k].y + h1(u)*p[k+1].y + h2(u)*p[k].slopey + h3(u)*p[k+1].slopey;
    glVertex2f(x,y);
   }
  }
  glEnd();
  glFlush();
  p[k+1].x=x; p[k+1].y=y;
//plotting the control points
 glEnable(GL_POINT_SMOOTH);
 glPointSize(5);
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_POINTS);
 for(k=0;k<=ncpoints;k++)
    glVertex2f(p[k].x,p[k].y); 
 glEnd();
 glFlush();
}

//getting the data
void getdata()
{
 int i;
 printf("Enter the no of control points max(10)\n");
 scanf("%d",&ncpoints);

 for(i=0;i<ncpoints;i++)
  {
   printf("Enter the vertex (x,y) of the control point %d\n",i);
   scanf("%f%f",&p[i].x,&p[i].y);
   printf("Enter the slopex and slopey of the control point %d\n",i);
   scanf("%f%f",&p[i].slopex,&p[i].slopey);
  }
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(-200,200,-200,200);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glFlush();
drawhermitespline();
}

int main(int argc, char** argv)
{
 getdata();
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
