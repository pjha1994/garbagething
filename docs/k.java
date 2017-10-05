import java.io.*;
import java.lang.Math;
class f
{
public boolean isPrime(long n)
    {
      if(n<2)
        return false;
      else if(n<=3)
        return true;
      if(n%2==0 || n%3==0)
        return false;
      for(int i=5;i<=Math.sqrt(n);i+=6)
      {
           if(n%i==0 || n%(i+2)==0)
             return false;
      }
      return true;
    }
}
class k
{
public static void main(String []args)throws IOException
{
f is=new f();
DataInputStream wow=new DataInputStream(System.in);

//System.out.println(is.isPrime(Integer.parseInt(wow.readLine())));
for(long i=0;i<(89);i++)
  if(is.isPrime(i))
    System.out.println(i);

}
}
