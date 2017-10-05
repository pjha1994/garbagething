#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct points
{
 int x;
 int y;
}s,p[100000];

struct circle
{
 int x;
 int y;
 int r;
} c1,c2;

//i1,i2intersection points

int status; //to store the status of intersection

void bresenhamcircle(int xcenter,int ycenter,int radius)
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

setPixel(xcenter+x,ycenter+y);
setPixel(xcenter+x,ycenter-y);
setPixel(xcenter-x,ycenter+y);
setPixel(xcenter-x,ycenter-y);
setPixel(xcenter+y,ycenter+x);
setPixel(xcenter+y,ycenter-x);
setPixel(xcenter-y,ycenter+x);
setPixel(xcenter-y,ycenter-x);
}
 glFlush();
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

void setPixel(int x,int y)
{
 glBegin(GL_POINTS);
  glVertex2f(x,y);
 glEnd();
}

int c2cintersection(int xa,int ya,int ra,int xb,int yb,int rb)
{
    /*
    ' This function checks for the intersection of two circles.
    ' If one circle is wholly contained within the other a -1 is returned
    ' If there is no intersection of the two circles a 0 is returned
    ' If the circles intersect a 1 is returned and
    ' the coordinates are placed in xi1, yi1, xi2, yi2
 
    ' dx and dy are the vertical And horizontal distances between
    ' the circle centers.
    */
 float a,d,h,x,y;
 int dx = abs(xb - xa);
 int dy = abs(yb - ya);
 
 d=sqrt((dx*dx)+(dy*dy));
 
 if(d >(ra + rb)) //no solution they do not intersect;
	return 0;
 if(d <abs(ra-rb))// circle is inside another circle
  	return -1;
 //s is the point where the line through circle intersection points cross through circle centres a is the distance to pselect from (xa,ya)//

 a = ((ra*ra) - (rb*rb) + (d*d)) / (2.0 * d) ;
 printf("\n%f",a);
 s.x=round(xa+dx*(a/d));
 s.y=round(ya+dy*(a/d));

 printf("distance b/w centres %f\ndistance a to p=%f\npoint p\n%d %d\n",d,a,s.x,s.y);
 return 1;
}


void getdata()
{
  c1.x=0;
  c1.y=0;
  c1.r=200;
  c2.x=250;
  c2.y=0;
  c2.r=100;
}


void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
}


void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
bresenhamcircle(c1.x,c1.y,c1.r);
bresenhamcircle(c2.x,c2.y,c2.r);
setPixel(s.x,s.y);
glFlush();
//drawaxes();
}


int main(int argc, char** argv)
{
 getdata();
 status=c2cintersection(c1.x,c1.y,c1.r,c2.x,c2.y,c2.r);
 printf("%d",status);
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
