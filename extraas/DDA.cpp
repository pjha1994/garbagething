#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
#include<math.h>
using namespace std;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0,255.0,255.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(int x,int y)
{
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}
void display()
{
        GLfloat x,y,a,b;
        cout<<"Enter the four coordinates\n";
        cin>>x>>y>>a>>b;
GLfloat m=(b-y)/(GLfloat)(a-x);
  if(m<0)
     m=m*(-1);
  if(m<1)
   {
   GLfloat j=y;
   for(GLfloat i=x;i<a;x++)
     {
       j=j+m;
       setPixel(i,j);
     }
   }
   else
   {
   GLfloat j=x;
   for(GLfloat i=y;i<b;i++)
    {
    j=j+1.0/m;
    setPixel(j,i);
    }
   }
}  
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
        
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
        return 0;
}
