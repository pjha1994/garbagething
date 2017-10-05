#include<iostream>
using namespace std; 
template <class T> T addition(T a,T b)//ERROR
{
  T r;
  r=a+b;
  return r;
}

int main()
{
cout<<"put 2 numbers"<<endl;
template <class T>T a,b;//ERROR
cin>>a;
cin>>b;

T z;
z=addition(a,b);

cout<<"your result is"<<z;

return 0;
}