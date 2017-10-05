#include<iostream>
#include<fstream>
#include<math.h>
bool isPrime(int);
using namespace std;
int main()
{
ofstream out("prime.txt");
int i;
for(i=0;i<100000000;i++)
 if(isPrime(i))
    {
    cout<<i<<"\n";
    out<<i<<"\n";
    }
return 0;
}

bool isPrime(int n)
    {
      if(n<2)
        return false;
      else if(n<=3)
        return true;
      if(n%2==0 || n%3==0)
        return false;
      for(int i=5;i<=sqrt(n);i+=6)
      {
           if(n%i==0 || n%(i+2)==0)
             return false;
      }
      return true;
    }
