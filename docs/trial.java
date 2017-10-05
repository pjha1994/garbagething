class search
{
public void bubble(int []a,int size)
 {
  for(int i=size-1;i>0;i--)
    for(int j=0;j<i;j++)
      if(a[j]>a[j+1])
        {
         int temp=a[j];
             a[j]=a[j+1];
           a[j+1]=temp;
        }
  for(int i=0;i<size;i++)
    System.out.print(a[i]+" ");
 }
public void selection(int []a,int size)
  {
  for(int i=0;i<size-1;i++)
   {
    int low=i;
     for(int j=i+1;j<size;j++)
           if(a[low]>a[j])
               low=j;
           if(low!=i)
            {
            int temp=a[low];
              a[low]=a[i];
                a[i]=temp;
            }
   }
for(int i=0;i<size;i++)
    System.out.print(a[i]+" ");
  }
public void insertion(int []a,int size)
  {
  for(int out=1;out<size;out++)
  {
    int temp=a[out];
    int in=out;
   while(in>0&&a[in-1]>=temp)
     {
      a[in]=a[in-1];
     --in;
     }
  a[in]=temp;
  }
  for(int i=0;i<size;i++)
    System.out.print(a[i]+" ");
  }
}
class m
{
public static void main(String [] args)
  {
   int a[]={2223,323,4,434,5,53,5,456,523,535,65,2,2345,346,34,62435346,2,623};
   int b[]={213,3,24,24,5,34,53,5,35,31,532,5342532,532,534,5,35,3,53,53,5,345,35,123,534,5,345,3};
   int c[]={2314,2354,3,565,6,5,87,678978,96,845,46,435,3,542,35,3245,435,34,52,54,56,86,5,5,42365,96,86,7,458,5,2346};
   search srch=new search(); 
    srch.bubble(a,a.length); 
        System.out.println("");
    srch.selection(b,b.length);
        System.out.println("");
    srch.insertion(c,c.length);
        System.out.println("");
  }


}
