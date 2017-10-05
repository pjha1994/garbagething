//bar chart


#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct periods
{
 float color[3];
 float x,y;
}s[8];

int n;

void drawbar(int x,int i)
{
glColor3fv(s[i].color);
glBegin(GL_POLYGON);
 glVertex2f(x,0);
 glVertex2f(x,s[i].y);
 glVertex2f(x+s[i].x,s[i].y);
 glVertex2f(x+s[i].x,0);
glEnd();
}


void drawchart()
{
int currentx=0;
int i;
for(i=0;i<n;i++)
 {
  drawbar(currentx,i);
  currentx+=s[i].x;
 }
}

void setColor(int i)
{
 if(i==0) { s[i].color[0]=1.0; s[i].color[1]=1.0; s[i].color[2]=1.0; }
else 
 if(i==1) { s[i].color[0]=1.0; s[i].color[1]=1.0; s[i].color[2]=0.0; }
else 
 if(i==2) { s[i].color[0]=1.0; s[i].color[1]=0.0; s[i].color[2]=1.0; }
else 
 if(i==3) { s[i].color[0]=1.0; s[i].color[1]=0.0; s[i].color[2]=0.0; }
else 
 if(i==4) { s[i].color[0]=0.0; s[i].color[1]=1.0; s[i].color[2]=1.0; }
else 
 if(i==5) { s[i].color[0]=0.0; s[i].color[1]=1.0; s[i].color[2]=0.0; }
else 
 if(i==6) { s[i].color[0]=0.0; s[i].color[1]=0.0; s[i].color[2]=1.0; }
else 
 if(i==7) { s[i].color[0]=0.0; s[i].color[1]=0.0; s[i].color[2]=0.0; }
}

void getdata()
{
 int i;
 printf("Enter the number of periods (max 8)\n");
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
 {
  printf("Enter the ending x value of period %d\n",i);
  scanf("%f",&s[i].x);
  printf("Enter the y value of period %d\n",i);
  scanf("%f",&s[i].y);
  setColor(i); 
 }
}

void init()
{
 glClearColor(0.0,0.0,0.0,0.0);
 glLoadIdentity();
 gluOrtho2D(-200,1800,-200,1400);
}

void drawaxes()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
	glVertex2f(0,-200);
	glVertex2f(0,2000);
	glVertex2f(-200,0);
	glVertex2f(2000,0);
glEnd();
glFlush();
}

void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glFlush();
 drawchart();
 drawaxes();
 glFlush();
}

int main(int argc, char** argv)
{
 getdata();
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500,400 );
 glutInitWindowPosition (0, 0);
 glutCreateWindow (" ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
