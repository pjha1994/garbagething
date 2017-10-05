//Incircle

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int x1,y11,x2,y2,x3,y3;
float incentrex,incentrey,radius;
float a,b,c,s,area;


void drawincircle()
{
 int i;
 float x,y;
 glColor3f(1.0,0.0,0.0);
 glBegin(GL_POINTS);
  for(i=0;i<360;i++)
  {
   x=incentrex+radius*cos((i*3.1459)/180);
   y=incentrey+radius*sin((i*3.1459)/180);
   //printf("%f %f\n",x,y);
   glVertex2f(x,y);
  }
 glEnd();
 glFlush();
}


void drawtriangle()
{
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_TRIANGLES);
  glVertex2f(x1,y11);
  glVertex2f(x2,y2);
  glVertex2f(x3,y3);
 glEnd();
 glFlush();
}

void incircle()
{
 a = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)) ;
 b = sqrt((x3-x1)*(x3-x1)+(y3-y11)*(y3-y11)) ;
 c = sqrt((x2-x1)*(x2-x1)+(y2-y11)*(y2-y11)) ;

 s=(a+b+c)/2;
 area = sqrt(s*(s-a)*(s-b)*(s-c)) ;
 radius = (area)/s ;

 incentrex = (a*x1+b*x2+c*x3)/(a+b+c) ;
 incentrey = (a*y11+b*y2+c*y3)/(a+b+c) ;

printf("a=%f b=%f c=%f\ns=%f area=%f\nradius=%f ix=%f iy=%f\n",a,b,c,s,area,radius,incentrex,incentrey) ;
printf("\n");
}


void getdata()
{
 printf("Enter the 3 Vertices of the triangle\n");
 printf("(x1,y1)\n");
 scanf("%d%d",&x1,&y11);
 printf("(x2,y2)\n");
 scanf("%d%d",&x2,&y2);
 printf("(x3,y3)\n");
 scanf("%d%d",&x3,&y3);
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
drawtriangle();
 drawincircle();
 drawaxes();
}

void drawaxes()
{
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_LINES);
	glVertex2i(0,-1000);
	glVertex2i(0,1000);
	glVertex2i(-1000,0);
	glVertex2i(1000,0);
 glEnd();
 glFlush();
}

int main(int argc, char** argv)
{
 getdata();
 incircle();
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
