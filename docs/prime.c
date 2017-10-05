#include<stdio.h>
#include<math.h>
void main()
{
int i;
for(i=0;i<100;i++)
 if(isPrime(i))
    printf("i= %d\n",i);
}

int isPrime(int n)
    {
         int i;
      if(n<2)
        return 0 ;
      else if(n<=3)
        return 1;
      if(n%2==0 || n%3==0)
        return 0;
      for(i=5;i<=int(sqrt(n));i+=6)
      {
           if(n%i==0 || n%(i+2)==0)
             return 0;
      }
      return 1;
    }
