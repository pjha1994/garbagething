#include<stdio.h>
#include<math.h>

typedef float mat3x3[3][3];
typedef float mat3x1[3][1];

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

int main()
{
 float x,y,tx,ty,xr,yr,xo,yo,angle,sx,sy;
 int ch;
 
do
 {
  printf("Enter your choice\n1.Translate\n2.Rotate\n3.Scale\n4.Exit\n") ;
  scanf("%d",&ch);
  
  switch(ch)
  {
   case 1:
   printf("\nEnter the point (x,y) to be translated: ");
   scanf("%f%f",&x,&y);
   printf("Enter the translation displacement (tx,ty): ");
   scanf("%f%f",&tx,&ty);
   input(x,y);
   translate(tx,ty);
   matrixproduct(tranmatrix,inmatrix);
   xo=output[0][0];
   yo=output[1][0];
   printf("\ntranslate\n%f %f\n\n",xo,yo);
   break;
 
   case 2:
   printf("\nEnter the point (x,y) to be rotated: ");
   scanf("%f%f",&x,&y);
   printf("Enter the angle of rotation: ");
   scanf("%f",&angle);
   printf("Enter the reference point(xr,yr): ");
   scanf("%f%f",&xr,&yr);
   input(x,y);
   translate(xr,yr);
   rotate(angle);
   matrixpreproduct(tranmatrix,rotmatrix);
   translate(-xr,-yr);
   matrixpreproduct(temp,tranmatrix);
   matrixproduct(temp,inmatrix);
   xo=output[0][0];
   yo=output[1][0];
   printf("\nrotate\n%f %f\n\n",xo,yo);
   break;

   case 3:
   printf("\nEnter the point (x,y) to be scaled: ");
   scanf("%f%f",&x,&y);
   printf("Enter the scale factor(sx,sy): ");
   scanf("%f%f",&sx,&sy);
   printf("Enter the reference point(xr,yr): ");
   scanf("%f%f",&xr,&yr);
   input(x,y);
   translate(xr,yr);
   scale(sx,sy);
   matrixpreproduct(tranmatrix,scalematrix);
   translate(-xr,-yr);
   matrixpreproduct(temp,tranmatrix);
   matrixproduct(temp,inmatrix);
   xo=output[0][0];
   yo=output[1][0];
   printf("\nscale\n%f %f\n\n",xo,yo);
   break;
  }
 } while(ch!=4);

 return 0;
}







