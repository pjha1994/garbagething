#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct points
{
 int x;
 int y;
}p[10],temp,temp1[10],temp2[10];


int n;

void getdata()
{
 /*int i;
 printf("Enter the number of vertices of the polygon: ");
 scanf("%d",&n);
 printf("Now Enter the x and y coordinates of the vertices\n");
 
 for(i=0;i<n;i++)
 {
  printf("Vertex %d\n",i);
  scanf("%d",&p[i].x); 
  scanf("%d",&p[i].y);
 }
*/
 n=0;
 FILE *IFP;
 int x,y;
 IFP=fopen("points.txt","r");
 while(fscanf(IFP,"%d %d",&x,&y)!=EOF)
 {
  printf("%d%d",x,y);
  p[n].x=x; p[n].y=y;
  n++; 
 }

}

void sort()
{
 int i,j,n1,n2;
 float centroidx,centroidy; 
 
 n1=n2=0;

//calculating the centroid
 for(i=0;i<n;i++)
 {
  centroidx+=p[i].x;
  centroidy+=p[i].y;
 }
 centroidx/=n;
 centroidy/=n;

//dividing the polygon into two parts
 for(i=0;i<n;i++)
 {
  if(p[i].y>=centroidy)
  {
   temp1[n1]=p[i];
   n1++;
  } 
  else
  {
   temp2[n2]=p[i];
   n2++;
  }
 }

//sorting part 1 and part2 (part1 based on increasing xaxis,part2 increasing y axis)
for(i=0;i<=n1;i++)//part 1
 for(j=0;j<(n1-1)-i;j++)
 {
  if(temp1[j].x>temp1[j+1].x)
  {
   temp=temp1[j];
   temp1[j]=temp1[j+1]; 
   temp1[j+1]=temp;
  }
 }

for(i=0;i<=n2;i++)//part2
 for(j=0;j<(n2-1)-i;j++)
 {
  if(temp2[j].x<temp2[j+1].x)
  {
   temp=temp2[j];
   temp2[j]=temp2[j+1]; 
   temp2[j+1]=temp;
  }
 }

//copying it into final structure
for(i=0;i<=n1;i++)
 p[i]=temp1[i];

for(i=0;i<=n2;i++)
 p[n1+i]=temp2[i];

//displaying data
 printf("\n");
 for(i=0;i<n1;i++)
   printf("\ntx=%d ty=%d",temp1[i].x,temp1[i].y);
 printf("\n");
 for(i=0;i<n2;i++)
   printf("\ntx=%d ty=%d",temp2[i].x,temp2[i].y);

 printf("\n");
 for(i=0;i<n;i++)
   printf("\nx=%d y=%d",p[i].x,p[i].y);

printf("\ncx=%f cy=%f\n",centroidx,centroidy); 
}


void drawpolygon()
{
 int i;
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_LINES);
  for(i=0;i<n-1;i++) 
  {
   glVertex2f(p[i].x,p[i].y);
   glVertex2f(p[i+1].x,p[i+1].y);
  }
  glVertex2f(p[i].x,p[i].y);
  glVertex2f(p[0].x,p[0].y);
 glEnd();

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
 drawpolygon();
 glFlush();
}

int main(int argc, char** argv)
{
 getdata();
 sort();
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
