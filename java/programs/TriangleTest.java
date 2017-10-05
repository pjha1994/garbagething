import java.io.*;
import java.util.Date; 
import java.util.ArrayList;
class Triangle
{
   double side1,side2,side3;
     
     Triangle(double a, double b, double c)
     {
     side1=a;side2=b;side3=c;
     }
     Triangle(double a)
     {
     side1=side2=side3=a;
     }
     Triangle()
     {
     side1=side2=side3=1.0d;
     }
     double getSide1() {return side1;}
     double getSide2() {return side2;}
     double getSide3() {return side3;}
    
     void setSide1(double newval) {side1 = newval;}
     void setSide2(double newval) {side2 = newval;}
     void setSide3(double newval) {side3 = newval;}

     double ComputePerimeter()
     {
     double s = (side1+side2+side3);
     return s;
     }
};

class TriangleTest {
     public static void main(String []a) {
         Triangle t1 = new Triangle(3,4,5);
         Triangle t2 = new Triangle(3);
         Triangle t3 = new Triangle();
         System.out.println("Perimeter of t1 = "+t1.ComputePerimeter());
         System.out.println("Perimeter of t2 = "+t2.ComputePerimeter());
         System.out.println("Perimeter of t3 = "+t3.ComputePerimeter());
     }
};

class MediaPlayer
{
    private String Name;
    private String Type;
    private String Color;
    private boolean FMsupported = false;
    private boolean isCDcompatable = false;
    
    MediaPlayer(String name, String type, String col)
    {
     this(name,type);Color=col;
    }
    
    MediaPlayer(String name, String type)
    {
    Name=name;Type=type;Color="gray";
    }
    MediaPlayer(String comp_name)
    { 
    Name=comp_name; Type="Radio";
    }
    String getName()  {return Name; }
    String getType()  {return Type; }
    String getColor() {return Color;}
    void setType(String newType) {Type=newType;}
    boolean isRadio() {return Type.equals("Radio");}
    boolean isIdentical(MediaPlayer another)
    {return this.getType().equals(another.getType());}
}  
class MediaTest
{
    public static void main(String a[])
    {
    MediaPlayer bpl = new MediaPlayer("BPL");
    MediaPlayer sansui = new MediaPlayer("Sansui");
    System.out.println("BPL type is "+bpl.getType());
    System.out.println("Sansui type is "+sansui.getType());
    System.out.println("Sansui color is "+sansui.getColor());
    System.out.println("The statement that types are equal is "+bpl.isIdentical(sansui));
    System.out.println(bpl);
    }
}

class PassByValue {
    public static void main(String [] args) {
             double one = 1.0;
              
             System.out.println("before: one = "+one);
             halveIt(one);
             System.out.println("after: one = "+one);
    }
    public static void halveIt(double arg) {
                arg/=2.0;
                System.out.println("halved: arg = "+arg);
    }
}
class PassByRef {
     public static void main(String [] args) {
            Body sirius = new Body("Sirius",null);
            System.out.println("before: "+sirius);
            commonName(sirius);           
            System.out.println("after: "+sirius);
     }
     public static void commonName(/*final*/ Body bodyRef) {
            bodyRef.name = "Dog Star";
            bodyRef=null;//Referred to null but the object still exists in main();Change made is still viisble in main's sirius.
//This isn't pass by reference.Java doesn't support pass by reference.
//Pass By Reference:means that when an argument is passed to a function, the invoked function gets a reference to the original value,not a copy of its value.If a function modifies its parameter,the value in the calling code will be changed because the argument and parameter use the same slot of memory.
//Java has only pass by value.It passes object references by value.Because two copies of same reference refer to the same actual object, changes made through one reference variable are visible through the other.
     }
}
class Body{
    public long idNum;
    public String name="<unnamed>";
    public Body orbits=null;
    public static long indexID=0;
    Body(){
       idNum=indexID++;
    }
    Body(String bodyName) {
         this(bodyName,null);
    }
    Body(String bodyName, Body orbitsAround) {
                this();
                name=bodyName;
                orbits=orbitsAround;
    }
    Body(Body other) {
       idNum=other.idNum;
       name=other.name;
       orbits=other.orbits;
    }
    public String toString() {
          String desc = idNum + "("+name+")";
          if(orbits!=null)
             desc+="orbits"+orbits.toString();
          return desc;
    }
}
class Run_Body{
    public void run(){
          Body mercury;
          Body sun=new Body();
          sun.idNum=Body.indexID++;
          sun.orbits=null;
          Body earth=new Body();
          earth.idNum=Body.indexID++;
          earth.orbits=sun;

    }
}
class field_initialization{
     double zero=0.0;
     double sum=4.5+3.7;
     double zeroCopy=zero;
     double rootTwo=Math.sqrt(2);
     double someVal=sum+2*Math.sqrt(rootTwo);
}
class c_o{
    public static void main(String [] args) {
               Body sun=new Body("Sol",null);
               Body earth=new Body("Earth",sun);
               System.out.println("Body "+earth.name+" orbits "+earth.orbits.name+" and has ID "+earth.idNum);
               System.out.println("Sun "+sun);
               System.out.println("Earth "+earth);
    }
}
class Body1{
    public long idNum;
    public String name = "<unnamed>";
    public Body orbits=null;
    
    private static long nextID = 0;
    
    {
    idNum=nextID++;
    }
    public Body1(String bodyName, Body orbitsAround)
    {
    name=bodyName;
    orbits= orbitsAround;
    }
}
class Primes{
     static int [] knownPrimes = new int[4]; 
     
     static {
          knownPrimes[0]=2;
          for(int i=1;i<knownPrimes.length;i++)
               knownPrimes[i] = nextPrime();
     }
     static int nextPrime(){return 1;}
}
class HelloWorld{
                public static void main(String []args)throws IOException {
                     System.out.println("Hello , World");
                     Run_ImprovedFibonacci a=new Run_ImprovedFibonacci();
                                           a.run();
                     Run_Fibonacci b=new Run_Fibonacci(); 
                                   b.run();
                     Run_Numbers c=new Run_Numbers();
                                 c.run(); 
                     Run_Point hash=new Run_Point();
                               hash.run();
                     Run_Deck d=new Run_Deck();
                              d.run();
                     Run_ArrayListExample e=new Run_ArrayListExample();
                                          e.run();
                     Run_StringsDemo f=new Run_StringsDemo();
                                     f.run();
                     Run_BetterStringsDemo g=new Run_BetterStringsDemo();
                                           g.run();
                     Run_Pixel h=new Run_Pixel();
                               h.run();
                     Run_Date1_Date2 i=new Run_Date1_Date2();
                                     i.run();
                     System.out.println(Point.origin);
 }
}
class Fibonacci{ 
 static  int MAX=50;
    public void fib(){
        int lo=1; 
        int hi=1;
        System.out.println(lo);
        while(hi<MAX){
              System.out.println(hi);
              hi=lo+hi;
              lo=hi-lo;
        }

   } 
}
class Run_Fibonacci{
      void run(){
          Fibonacci nf=new Fibonacci();
          nf.fib();
      }
}
class Suit{
     final static int CLUBS=1;
     final static int DIAMONDS=2;
     final static int HEARTS=3;
     final static int SPADES=4;
}
class CircleStuff{
}
class ImprovedFibonacci{
     static final int MAX_INDEX=9;
     public void fib(){
           long lo=1,hi=1;
           String mark;
           System.out.println("1: "+lo);
           /*for(int i=2;i<=MAX_INDEX;i++){
                if(hi%2==0)
                    mark="*";
                else
                    mark="";
                System.out.println(i+": "+hi+mark);
                hi=lo+hi;
                lo=hi-lo;
           }*/
            int i=2;
           while(i<=MAX_INDEX){
                if(hi%2==0)
                    mark="*";
                else
                    mark="";
                System.out.println(i+": "+hi+mark);
                hi=lo+hi;
                lo=hi-lo;
                  i++;
           }


     } 

}
class Run_ImprovedFibonacci{
      void run(){
           ImprovedFibonacci nf=new ImprovedFibonacci();
              nf.fib();

      }


}
class Color{
}
class Point{
      public double x,y;
      public static Point origin=new Point();
      Point(){x=0.0;y=0.0;}
      Point(double x,double y){this.x=x;this.y=y;}
      double getx(){return x;}
      double gety(){return y;}
      void setx(double val){x=val;}
      void sety(double val){y=val;}
      double getNorm(){return Math.sqrt(x*x+y*y);}
      public double distance(Point that){
                    double xdiff=this.x-that.x;
                    double ydiff=this.y-that.y;
                    return Math.sqrt(xdiff*xdiff+ydiff*ydiff);
      }
      public void clear(){x=0;y=0;}
}
class Run_Point{
       void run(){
            Point p1=new Point(3.0,4.0);
            Point p2=new Point();
            System.out.println("The norm of point (3,4) is "+p1.getNorm());
            System.out.println("Distance between p1(3,4) and p2(0,0) is "+p1.distance(p2));
            Point lowerLeft=new Point();
            Point upperRight=new Point();
            Point middlePoint=new Point();
                  lowerLeft.x=0.0;lowerLeft.y=0.0;
                  upperRight.x=1280.0;upperRight.y=1024.0;
                  middlePoint.x=640.0;middlePoint.y=512.0;
             System.out.println("Distance between lowerLeft(0,0) and upperRight(1280.0,1024.0) is "+lowerLeft.distance(upperRight));
       }
}
class Pixel extends Point{
            Color color;
            public void clear() {
                        super.clear();
                        color=null;
                        super.clear();
            }
}
class Run_Pixel{
      public void run(){
             Pixel newPixel=new Pixel();
                   newPixel.clear();
                   Object oref=new Pixel();
                          oref="Some String";
                   System.out.println(oref);
                   Point point=new Pixel();
                         point.clear();
      }
}
class Numbers{
      private int num;
      Numbers(int n){num=n;}
      public int get_num(){return num;}
      public void PrimeList(){
             int i,j; 
             System.out.println("The prime numbers less than "+num+" are :");
             for(j=1;j<num;j++)
             {
             int flag=0;
               for(i=2;i<Math.sqrt(j);i++)
                   if(j%i==0)
                     {flag=1;break;}
                    if(flag==0)
                        System.out.println(j);
             }
      }
      public void PrimeList1(){
             int i,j;
             for(j=num-1;j>=1;j--)
                 {
                  int flag=0;
                    {
                    for(i=2;i<Math.sqrt(j);i++)
                        if(j%i==0)
                          {flag=1;break;}
                        if(flag==0)
                          System.out.println(j);
                    }
                  }
      }
      public int exponent(int x){ 
             int p=1;
             for(int i=1;i<=x;i++)
                  p=p*num;
             return p;
      }
      public double computepower(int x){
             if(x>1) return num*computepower(x-1);
             else if(x<0) return 1.0/computepower(-x);
             else return(x==0?1.0:num);
      }
      public long factorial(){
             long p=1;
             for(long i=num;i>0;i--)     
                 p=p*i;
             return p;
      }
      public long computefactorial(){
             long result=1;
             for(int j=2;j<num;result*=j,j++);
             return result;
      }
}

class Run_Numbers{
          void run()throws IOException{
               DataInputStream wow=new DataInputStream(System.in);
               System.out.println("Enter a number : ");
                   int j=Integer.parseInt(wow.readLine());
               Numbers n=new Numbers(j);
                       System.out.println("\n");
                       n.PrimeList(); n.PrimeList1();
               System.out.println("Enter a number for which the earlier entered number be raised to the power of:\n");
                       j=Integer.parseInt(wow.readLine());
                       System.out.println(n.get_num()+"^"+j+" = "+n.computepower(j));
               System.out.println(n.get_num()+"! = "+n.computefactorial());
          }
}

class Deck{
       public static final int DECK_SIZE=52;
      /* private Card[] cards=new Card[DECK_SIZE];
    
       public void print(){
                   for(int i=0;i<cards.length;i++)
                            System.out.println(cards[i]);
       }*/
       static double  average(int[] values){
                      if(values==null)
                              throw new IllegalArgumentException();
                      else if(values.length==0)
                              throw new IllegalArgumentException();
                      else{
                          double sum=0.0;
                          for(int i=0;i<values.length;i++)
                               sum+=values[i];
                          return sum/values.length; 
                      }                  
       }

       static double average1(int[] values){
                    /*if(values==null |values.length==0)*/
                    if(values==null || values.length==0)
                            throw new IllegalArgumentException(); 
                    else{
                          double sum=0.0;
                          for(int i=0;i<values.length;i++)
                               sum+=values[i];
                          return sum/values.length; 
                      }    


       }
}
class Run_Deck{
      void run()throws IOException{
          DataInputStream wow=new DataInputStream(System.in);
          Deck newDeck=new Deck();
              System.out.print("Enter the limit for the array :");
              int x=Integer.parseInt(wow.readLine());
              int a[]=new int[x];
              /* int i=0;
               do{
                  System.out.print("Enter the "+i+"th number : ");
                  a[i]=(Integer.parseInt(wow.readLine()));i++;
               }while(i<x);*/
                for(int i=0;i<x;i++){
                    System.out.print("Enter the "+i+"th number : ");
                    a[i]=(Integer.parseInt(wow.readLine()));
                }
                System.out.println("The average is :"+newDeck.average1(a));

      }



}

class Date1{
     public void l(){
            java.util.Date now=new java.util.Date();
            System.out.println(now);
     }
}

class Date2{
      public void l(){
             Date now=new Date();
             System.out.println(now);
      }
}


class Run_Date1_Date2{
      public void run(){
             Date1 a=new Date1();
             Date2 b=new Date2();
                  a.l();
                  b.l();
      }
} 

class ArrayListExample{
      public void l(){
                  ArrayList List;
                            List=new ArrayList();
                            List.add("Ramesh");
                  System.out.println("\n\nLength of the array now is "+List.size());
                            List.add("Kishore");
                  System.out.println("Length of the array now is "+List.size());
                            List.add("Siva");
                  System.out.println("Length of the array now is "+List.size());
                       for(int i=0;i<List.size();i++)
                             System.out.println(List.get(i));
                             System.out.println("\n\n");
      }
}
class Run_ArrayListExample{
      public void run(){
             ArrayListExample array=new ArrayListExample();
                  array.l();
      }
}


class StringsDemo{
      void l(){
           System.out.println("Hello, World!");

           String myName="Maximus";
           myName=myName+" Lucius";
           System.out.println(myName);
      }
}
class Run_StringsDemo{
      public void run(){
                StringsDemo newStringsDemo=new StringsDemo();
                            newStringsDemo.l();
      }
}
class BetterStringsDemo{
         public void l(){
                String myName=" Lucius ";
                String occupation=" Warrior ";  
                myName+=" Arbiter ";
                myName+=" ";
                myName+="("+occupation+")";
                System.out.println("Name = "+myName);
                System.out.println("Length of the above string is : "+myName.length());
                System.out.println("Printing character by character : ");
                
                for(int i=0;i<=myName.length()-1;i++)
                     System.out.print(myName.charAt(i)+" ");
                System.out.println("\n");
                char ar[]=new char[myName.length()];
                for(int i=0;i<=myName.length()-1;i++)
                     ar[i]=myName.charAt(i);      
                String constructor_string=new String(ar);
                System.out.println("Name = "+constructor_string);
              

                char k[]=myName.toCharArray();
                    for(int i=0;i<=myName.length()-1;i++)
                     System.out.print(k[i]+" ");

                String x=new String(k);
                System.out.println("\nName = "+x);
                   if(x.equals(myName)) 
                        System.out.println(x.equals(myName));
                    System.out.println(x==myName);
         }
}
class Run_BetterStringsDemo{
           public void run(){
                    BetterStringsDemo a=new BetterStringsDemo();
                       a.l();
           }
}
class str{
    public static void main(String [] args)throws IOException {
                 String p="PEEKABOOP";
                 System.out.println("String is "+p);
                 int counts[]=new int[123];
                 for(int i=0;i<p.length();i++)
                       counts[p.charAt(i)]++;//Counts number of times a character appears.
                  System.out.println(counts);
                 for(int i=0;i<p.length();i++)
                  System.out.println(p.charAt(i)+" appears "+counts[p.charAt(i)]+" times ");
                 System.out.println(countBetween(p,'P'));
                 string_compares(p);
    }
    static int countBetween(String s, char ch){
            int begPos=s.indexOf(ch);
            if(begPos<0)
                return -1;
            int endPos=s.lastIndexOf(ch);
            return endPos-begPos-1; 
    }
    static void string_compares(String s)throws IOException{
           for(int i=0;i<s.length();i++)
           System.out.println(s.indexOf(s.charAt(i)));//Searching forward,the first occurence of the character.
           System.out.println(s.indexOf('O',5));//second index must be less than the first occurence of the character else -1 is returned
           System.out.println(s.indexOf("KA"));//Searches forward for first index of the string inside s
           System.out.println(s.indexOf("KA",2));
           System.out.println(s.lastIndexOf('E'));
           System.out.println(s.lastIndexOf('O',6));
           System.out.println(s.lastIndexOf("BO"));
           System.out.println(s.lastIndexOf("EE",6));
                  System.out.println("\u00e7"+"      "+"\u0063");//These two unicodes are different but mean the same in english and french.While sorting strings, this should be taken into account.
                  System.out.println("s".equals(s));//Strings can be switched places,or both can be in double arguments.Returns true if both strings have same length and same unicode characters
                    System.out.println("FAX".equalsIgnoreCase("fax"));
                    System.out.println("HEY".compareTo("a"));
                    System.out.println("ghj".compareToIgnoreCase("GHJ"));
                    System.out.println("LOOK, look!".regionMatches(6,"LOOK",0,4));
                    System.out.println("LOOK, look!".regionMatches(true,6,"LOOK",0,4));
                    System.out.println("LOOK, look!".regionMatches(true,6,"LOOK",0,5));
                    System.out.println(s.startsWith("PEE", 0));
                    System.out.println(s.startsWith("PEE"));
                    System.out.println(s.endsWith("P"));
                    String x=new String("PEEKABOOP");
                    System.out.println(x==s);//False.Even same value, yet not equal as they are different objects.
                    String z="PEEKABOOP";//A string literal represents the same object everywhere, here z and s both point to "PEEKABOOP"
                    System.out.println(z==s);//True.Any two string literals with the same contents will refer to the same String object, always.
                    System.out.println("Enter PEEKABOOP");
                    String a=read();
                    System.out.println(s==a);//false AS IT IS AN MANUFACTURED OBJECT,not literal anymore.
                                        










    }
    static int putIn(String key){
             String unique=key.intern();
             int i;
              for(i=0;i<tableSize;i++)
                 if(table[i]==unique)
                    return i;
                 table[i]=unique;
                 tableSize++;
                  return i;

    }
    /*static int position(String key){//bINARY SEARCH FOR A SORTED LIST OF STRINGS
            String[]table={"werwr","","wwtert","EWRT","ER","Tew","Tew","teR","TAERR","tEAR","tW","tER","teR","ter","te'yrt'asG","FdhjmnR","Syw'tRT'","j'aYWTE"};
            int lo=0;
            int hi=table.length-1;
             while(lo<=hi) {
                int mid = lo+ (hi-lo)/2;
                int cmp = key.compareTo(table[mid]);
                if(cmp==0)
                   return mid;
                else if(cmp<0)
                  hi = mid-1;
                else
                  lo= mid+1;
             } 
            return -1;
    }*/
    static String read() 
         throws IOException
    {
        DataInputStream wow=new DataInputStream(System.in);
                   return wow.readLine();
    }
}
