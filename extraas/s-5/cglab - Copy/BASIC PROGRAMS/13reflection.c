//13 . reflection wrt any line error

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

//Mathematical part

struct points
{
float x;
float y;
}p[10],save[10];

typedef float mat3x3[3][3];
typedef float mat3x1[3][1];

float a,b,c,d;
int n;

mat3x1 inmatrix,output;
mat3x3 temp,tranmatrix,rotmatrix,reflectmatrix;


void reflectx()
{
 reflectmatrix[0][0]=1;
 reflectmatrix[1][1]=-1;
 reflectmatrix[2][2]=1;

reflectmatrix[0][1] = reflectmatrix[0][2] = reflectmatrix[1][0] = reflectmatrix[1][2] = reflectmatrix[2][0] = reflectmatrix[2][1] = 0;
}

void reflecty()
{
 reflectmatrix[0][0]=-1;
 reflectmatrix[1][1]=1;
 reflectmatrix[2][2]=1;
 
reflectmatrix[0][1] = reflectmatrix[0][2] = reflectmatrix[1][0] = reflectmatrix[1][2] = reflectmatrix[2][0] = reflectmatrix[2][1] = 0;
}

void reflectpxy()
{
 reflectmatrix[0][0]=-1;
 reflectmatrix[1][1]=-1;
 reflectmatrix[2][2]=1;

reflectmatrix[0][1] = reflectmatrix[0][2] = reflectmatrix[1][0] = reflectmatrix[1][2] = reflectmatrix[2][0] = reflectmatrix[2][1] = 0;
}

void reflectyx()
{
 reflectmatrix[0][1]=1;
 reflectmatrix[1][0]=1;
 reflectmatrix[2][2]=1;

reflectmatrix[0][0] = reflectmatrix[0][2] = reflectmatrix[1][1] = reflectmatrix[1][2] = reflectmatrix[2][0] = reflectmatrix[2][1] = 0;
}

void reflectymx()
{
 reflectmatrix[0][1]=1;
 reflectmatrix[1][0]=-1;
 reflectmatrix[2][2]=1;

reflectmatrix[0][0] = reflectmatrix[0][2] = reflectmatrix[1][1] = reflectmatrix[1][2] = reflectmatrix[2][0] = reflectmatrix[2][1] = 0;
}

void translate(float tx,float ty)
{
 tranmatrix[0][2]=tx;
 tranmatrix[1][2]=ty;
 tranmatrix[2][2]=tranmatrix[1][1]=tranmatrix[0][0]=1;
}

void rotate(float theta)
{
 rotmatrix[0][0]=cos(theta);
 rotmatrix[0][1]=-sin(theta);
 rotmatrix[1][0]=sin(theta);
 rotmatrix[1][1]=cos(theta);
 rotmatrix[2][2]=1;
}

void input(float x,float y)
{
 inmatrix[0][0]=x;
 inmatrix[1][0]=y;
 inmatrix[2][0]=1;
}

void matrixpreproduct(mat3x3 a,mat3x3 b)
{
mat3x3 c;
int i,j,k;
for(i=0;i<3;i++)
 for(j=0;j<3;j++)
 {
  c[i][j]=0;
  for(k=0;k<3;k++)
   c[i][j]+=a[i][k]*b[k][j];
 }

for(i=0;i<3;i++)
 for(j=0;j<3;j++)
  temp[i][j]=c[i][j];
}

void matrixproduct(mat3x3 a,mat3x1 b)
{
 int i,j,k;
 for(i=0;i<3;i++)
  for(j=0;j<1;j++)
  {
   output[i][j]=0;
   for(k=0;k<3;k++)
    output[i][j]+=a[i][k]*b[k][j];
  }
}

void transform()
{
 float angle,con;
 int i;
 int ch;

 printf("Enter the no of vertices of the polygon: ");
 scanf("%d",&n);
 printf("Enter the vertices(x,y)\n");
 for(i=0;i<n;i++)
  {
  scanf("%f%f",&p[i].x,&p[i].y);
  save[i]=p[i];
  }
 
 glColor3f(0.0,0.0,1.0);
  drawPolygon();

do
 {
  printf("Enter your choice\n1.Refelction wrt x axis\n2.Refelction wrt y axis\n3.Refelction p'lr to xy plane\n4.Reflection wrt y=x\n5.Reflection wrt y=-x\n6.Reflection wrt any line\n7.exit\n") ;
  scanf("%d",&ch);
  
  switch(ch)
  {
   case 1:
   for(i=0;i<n;i++)
    {
    input(p[i].x,p[i].y);
    reflectx();
    matrixproduct(reflectmatrix,inmatrix);
    save[i].x=output[0][0];
    save[i].y=output[1][0];
    }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
   break;
 
   case 2:
   for(i=0;i<n;i++)
   {
    input(p[i].x,p[i].y);
    reflecty();
    matrixproduct(reflectmatrix,inmatrix);
    save[i].x=output[0][0];
    save[i].y=output[1][0];
   }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
   break;
 
   case 3:
   for(i=0;i<n;i++)
   {
    input(p[i].x,p[i].y);
    reflectpxy();
    matrixproduct(reflectmatrix,inmatrix);
    save[i].x=output[0][0];
    save[i].y=output[1][0];
   }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
   break;

   case 4:
   for(i=0;i<n;i++)
   {
    input(p[i].x,p[i].y);
    reflectyx();
    matrixproduct(reflectmatrix,inmatrix);
    save[i].x=output[0][0];
    save[i].y=output[1][0];
   }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
   break;

   case 5:
   for(i=0;i<n;i++)
   {
    input(p[i].x,p[i].y);
    reflectymx();
    matrixproduct(reflectmatrix,inmatrix);
    save[i].x=output[0][0];
    save[i].y=output[1][0];
   }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
   break;

   case 6:
   scanf("%f%f%f%f",&a,&b,&c,&d);
   glColor3f(1.0,0.0,0.0);
   drawline(a,b,c,d);
   angle=atan(d-b/c-a);
  // con = a - ((d-b)/(c-a)) * b;
   for(i=0;i<n;i++)
   {
   input(p[i].x,p[i].y);
   //translate(0,con);
   rotate(angle);
   //matrixpreproduct(tranmatrix,rotmatrix);
   reflectpxy();
   matrixpreproduct(rotmatrix,reflectmatrix);
   rotate(-angle);
   matrixpreproduct(temp,rotmatrix);
   //translate(0,-con);
   //matrixpreproduct(temp,tranmatrix);
   matrixproduct(temp,inmatrix);
   save[i].x=output[0][0];
   save[i].y=output[1][0];
   }
   glColor3f(1.0,0.0,1.0);
    drawPolygon();
   break;
  }
 } while(ch!=7);
exit(0);
}


//openGL part
void init()
{
 glClearColor(0.0,0.0,0.0,0.0);
 glLoadIdentity();
 gluOrtho2D(-1000,1000,-1000,1000);
}

void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glutSwapBuffers();
 transform();
 glFlush();
}

void drawline()
{
 glBegin(GL_LINES);
  glVertex2f(a,b);
  glVertex2f(c,d);
 glEnd();
 glutSwapBuffers();
}

void drawPolygon()
{
 int i;
 glBegin(GL_POLYGON);
  for(i=0;i<n;i++)
   glVertex2f(save[i].x,save[i].y);
 glEnd();
 glFlush();
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





