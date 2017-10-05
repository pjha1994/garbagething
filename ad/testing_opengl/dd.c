//dda line


#include<glut.h>

#include<stdio.h>

#include<math.h>


void setPixel(int x,int y);
void ddaline(int x0,int y0,int x1,int y1);

int roundnum(double number)
;
int a,b,c,d;


void init()

{

glClearColor(0.0,0.0,0.0,0.0);

glLoadIdentity();

gluOrtho2D(-300,300,-300,300);

}


void display()

{

glClear(GL_COLOR_BUFFER_BIT);

glMatrixMode(GL_PROJECTION);

glFlush();

glColor3f(1.0,1.0,1.0);

ddaline(0,-300,0,300);

ddaline(-300,0,300,0);

glColor3f(1.0,1.0,0.0);

ddaline(a,b,c,d);



}


void ddaline(int x0,int y0,int x1,int y1)

{

int dy=y1-y0;

int dx=x1-x0;

int steps,i;


float xinc,yinc,x=x0,y=y0;


if(abs(dx)>abs(dy))

 steps=abs(dx);

else
 
 steps=abs(dy);


xinc=(float)dx/(float)steps;

yinc=(float)dy/(float)steps;


setPixel(roundnum(x),roundnum(y));


for(i=0;i<steps;i++)

{

 x+=xinc;
 
y+=yinc;
 
setPixel(roundnum(x),roundnum(y));

}

//glutSwapBuffers();

glFlush();

}


int roundnum(double number)

{

 return (number>=0) ? (int)(number+0.5):(int)(number-0.5);

}



void setPixel(int x,int y)

{

glBegin(GL_POINTS);
 
glVertex2f(x,y);

glEnd();

}


int main(int argc, char** argv)

{

 printf("Enter (x1,y1)\n");

 scanf("%d%d",&a,&b);
 
printf("Enter (x2,y2)\n");
 
scanf("%d%d",&c,&d);

 glutInit(&argc, argv);

 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 
glutInitWindowSize (600, 600);

 glutInitWindowPosition (100, 100);

 glutCreateWindow (" dda line ");

 init ();

 glutDisplayFunc(display);
 glutMainLoop();
 
 return 0;

}
