//Linefill rectangle

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void drawline(int x1,int y1,int x2,int y2)
{
glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
glEnd();
}

void fill()
{
int i,j,k,l;
glColor3f(1.0,1.0,1.0);
glLineWidth(5);
drawline(400,200,400,800);
drawline(400,800,800,800);
drawline(800,800,800,200);
drawline(400,200,800,200);
glFlush();
glColor3f(0.0,0.0,1.0);
glLineWidth(1);

for(i=201;i<800;i++)
{	
 drawline(400,i,800,i);
 glFlush();
 for(k=0;k<1000;k++)
  for(j=0;j<1000;j++)
   l=0;
}
exit(0);
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
gluOrtho2D(0,1000,0,1000);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glFlush();
fill();
}

int main(int argc, char** argv)
{
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
