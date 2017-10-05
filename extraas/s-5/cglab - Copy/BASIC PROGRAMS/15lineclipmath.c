#include<stdio.h>

#define ACCEPT(a,b) (!(a|b))
#define REJECT(a,b) (a&b)
#define INSIDE(a)   (!a)


unsigned char code1,code2;
float x1,y1,x2,y2;
int xwmin,xwmax,ywmin,ywmax;

//function to find the codes of line endpoints
unsigned char findcode(float x,float y)
{
 unsigned char code=0x0;
 if(x<xwmin)
   code=(code|0x1);
 if(x>xwmax)
   code=(code|0x2);
 if(y<ywmin)
   code=(code|0x4);
 if(y>ywmax)
   code=(code|0x8);
 return code;
}

//function to swap the codes and endpoints
void swap()
{
 unsigned char tempcode;
 float tempx,tempy;
 
 tempcode=code1;
 tempx=x1;
 tempy=y1;
 
 code1=code2;
 x1=x2;
 y1=y2;
 
 code2=tempcode;
 x2=tempx;
 y2=tempy;
}

//clipping function
int main()
{
 int done=0;
 float m;
 if(x2!=x1)
  m=((y2-y1)/(x2-x1)); 
 
 while(done==0)
 {
  code1=findcode(x1,y1); 
  code2=findcode(x2,y2);
 
  if ACCEPT(code1,code2)
  {
   done=1;
   printf("Line Accepted (%f,%f)(%f,%f)\n",x1,y1,x2,y2);
   glColor3f(0.0,0.0,1.0);
    drawline();
  }

  else 
  if REJECT(code1,code2)
  {
   done=1;
   printf("Line Rejected (%f,%f)(%f,%f)\n",x1,y1,x2,y2);
  }

  else
  if INSIDE(code1)
	swap();
 
  if(code1 & 0x1)
  {
   y1=y1+(xwmin-x1)*m;
   x1=xwmin;
  }
  
  if(code1 & 0x2)
  {
   y1=y1+(xwmax-x1)*m;
   x1=xwmax;
  }
  
  if(code1 & 0x4)
  {
   if(x1!=x2)
    x1=x1+((ywmin-y1)/m);
   y1=ywmin;
  }

  if(code1 & 0x8)
  {
   if(x2!=x1)
    x1=x1+((ywmax-y1)/m);
   y1=ywmax;
  }
 }
return 0;
}
