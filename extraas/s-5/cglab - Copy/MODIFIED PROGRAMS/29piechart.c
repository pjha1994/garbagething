#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct sections
{
 float angle;
 float color[3];
 float amount;
}s[8];

int n;
float currentangle,nextangle;

void drawarc(int start,int end,int c)
{
 float xp,yp,i;
 glLineWidth(10);
 for(i=start;i<=end;i++)
 {
  glColor3fv(s[c].color);
  xp=500*cos(3.14*(i/180));
  yp=500*sin(3.14*(i/180));
  glBegin(GL_LINES);
   glVertex2f(0,0);
   glVertex2f(xp,yp);
  glEnd();
  
  glPointSize(2);
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POINTS);
   glVertex2f(xp,yp);
  glEnd();  
 }
}


void drawchart()
{
int i;
currentangle=0;
for(i=0;i<n;i++)
 {
  drawarc(currentangle,currentangle+s[i].angle,i);
  currentangle+=s[i].angle;
 }
}

void calculateangle()
{
int i;
float totalamount=0;
for(i=0;i<n;i++)
 totalamount+=s[i].amount;
for(i=0;i<n;i++)
 s[i].angle=(s[i].amount/totalamount)*360;
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
 printf("Enter the number of sections (max 8)\n");
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
 {
  printf("Enter the attribute of section %d\n",i);
  scanf("%f",&s[i].amount);
  setColor(i); 
 }
calculateangle();
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
 glMatrixMode(GL_PROJECTION);
 glFlush();
 drawchart();
 glFlush();
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
