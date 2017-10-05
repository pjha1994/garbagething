#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

//Mathematical part

struct points
{
float x;
float y;
}p[10];

typedef float mat3x3[3][3];
typedef float mat3x1[3][1];

int n;

mat3x1 inmatrix,output;
mat3x3 temp,tranmatrix,rotmatrix,scalematrix;

void translate(float tx,float ty)
{
 tranmatrix[0][2]=tx;
 tranmatrix[1][2]=ty;
 tranmatrix[2][2]=tranmatrix[1][1]=tranmatrix[0][0]=1;
}

void rotate(float angle)
{
float theta=3.14159*(angle/180);
 rotmatrix[0][0]=cos(theta);
 rotmatrix[0][1]=-sin(theta);
 rotmatrix[1][0]=sin(theta);
 rotmatrix[1][1]=cos(theta);
 rotmatrix[2][2]=1;
}

void scale(float sx,float sy)
{
 scalematrix[0][0]=sx;
 scalematrix[1][1]=sy;
 scalematrix[2][2]=1;
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
 int i;
 float tx,ty,xr,yr,angle,sx,sy;
 int ch;

 printf("Enter the no of vertices of the polygon: ");
 scanf("%d",&n);
 printf("Enter the vertices(x,y)\n");
 for(i=0;i<n;i++)
  scanf("%f%f",&p[i].x,&p[i].y);
 
 glColor3f(0.0,0.0,1.0);
  drawPolygon();

do
 {
  printf("Enter your choice\n1.Translate\n2.Rotate\n3.Scale\n4.Exit\n") ;
  scanf("%d",&ch);
  
  switch(ch)
  {
   case 1:
   printf("Enter the translation displacement (tx,ty): ");
   scanf("%f%f",&tx,&ty);
   for(i=0;i<n;i++)
   {
    input(p[i].x,p[i].y);
    translate(tx,ty);
    matrixproduct(tranmatrix,inmatrix);
    p[i].x=output[0][0];
    p[i].y=output[1][0];
   }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
   break;
 
   case 2:
   printf("Enter the angle of rotation: ");
   scanf("%f",&angle);
   printf("Enter the reference point(xr,yr): ");
   scanf("%f%f",&xr,&yr);
   for(i=0;i<n;i++)
   {
    input(p[i].x,p[i].y);
    translate(xr,yr);
    rotate(angle);
    matrixpreproduct(tranmatrix,rotmatrix);
    translate(-xr,-yr);
    matrixpreproduct(temp,tranmatrix);
    matrixproduct(temp,inmatrix);
    p[i].x=output[0][0];
    p[i].y=output[1][0];
   }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
   break;

   case 3:
   printf("Enter the scale factor(sx,sy): ");
   scanf("%f%f",&sx,&sy);
   printf("Enter the reference point(xr,yr): ");
   scanf("%f%f",&xr,&yr);
   for(i=0;i<n;i++)
   {
    input(p[i].x,p[i].y);
    translate(xr,yr);
    scale(sx,sy);
    matrixpreproduct(tranmatrix,scalematrix);
    translate(-xr,-yr);
    matrixpreproduct(temp,tranmatrix);
    matrixproduct(temp,inmatrix);
    p[i].x=output[0][0];
    p[i].y=output[1][0];
   }
   glColor3f(0.0,1.0,1.0);
    drawPolygon();
  }
 } while(ch!=4);
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

void drawPolygon()
{
 glClear(GL_COLOR_BUFFER_BIT);
 int i;
 glBegin(GL_POLYGON);
  for(i=0;i<n;i++)
   glVertex2f(p[i].x,p[i].y);
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





