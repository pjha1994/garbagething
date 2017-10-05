import java.io.*;
//import java.util.*;
import java.util.Date;  //Importing individually for each
import java.util.ArrayList;
//package com.sum.games;Importing a package

//Java language designed for maximum potability
//Source code compiled to java Bytecodes, whic is designed to be run on a Java virtual machine.
//Other languages can also be compiled into javabytecodes.
//platform independent:java bytecodes can run on any JVM
//JVM, a runt-time system that provides a mechanism for object creation.
class HelloWorld{
   //public main method so that anyone can execute it, here JVM
   //only parameter is an array of string type objects
   //name+parameter list==signature of a method;name+parameter+any modifiers==header
   //method declaration is header+body
   //out is object reference, println() is the method; Out is static field of class system.
   //String Literal=="Hello, World"
   //primitive types==boolean,char,byte,short,int,long,float,double
   //local variable undefined prior to initialization
   //presence of line breaks makes no difference to the meaning of the statement---line-breaks,spaces,tabs and other other white space are purely for the programmer's convenience
   //while ends on:condition being false,break statement,exception
   //println is overloaded
   /*this is second type of comment*/
   /**this is documentation comment, to be at the top*/
   //constant==literals like 50, "hello"
   //named constants are final. static 
   //identifiers, techincal term for names
   //flow of control--while,for,if-else,switch,do-while.
   //for loop is a shorthand of while loop.
   //i++,i+=1,i=i+1; += -= *= /=  ;
   //(classes or interfaces(classes or interfaces(methods(fields)))) classes or interfaces can be members of other classes and interfaces
   //Every object has a class that defines its data and behaviour:Three kinds of members
                                                                //Fields:Data variables 
                                                                //Methods:contain executable code
                                                                //Classes and interfaces



















   public static void main(String []args)throws IOException {//static because main method belongs to the class and not to a particular instance of the class
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
 static  int MAX=50;//make it static final int MAX=50;
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
          //Fibonacci.MAX=56;//Accessing a static member is like accesssing as class member, rather than an instance member.
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
     /*static final double "uO3CO"=3.14159265358979323846;write the unicode for pi on L.H.S of equal sign*/
}
class ImprovedFibonacci{
     static final int MAX_INDEX=9;
     public void fib(){
           long lo=1,hi=1;
           String mark;
           System.out.println("1: "+lo);//or String temp="1: "+lo;System.out.println(temp);
           /*Both for and while loops are equivalent as depicted below*/  
           /*Variables can be declared in for loop's initilization statements*/
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
                System.out.println(i+": "+hi+mark);//The '+' operator is a concatenation opearator when at least one of its operands is a string and an addition operator otherwise.
                //A separator string and a marker string
                hi=lo+hi;
                lo=hi-lo;
                  i++;
           }


     } 

}
class Run_ImprovedFibonacci{
      void run(){
           ImprovedFibonacci nf=new ImprovedFibonacci();//Every object has a class that defines its data and behaviour.
              nf.fib();

      }


}
class Point{
      public double x,y;//Two fields, x and y
                        //Members of a class can have various levels of visibility and accessibility
                        //Public x and y means any code can access them
                        //Other levels of accesssibility limit member access to code in the class itself or to other releated classes
      public static Point origin=new Point();//values of x and y are zero
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
                    return Math.sqrt(xdiff*xdiff+ydiff*ydiff);//Type of return value must be compitable with the return type in the header
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
class Pixel extends Point{  //Extends both data and behaviour of the Point superclass.Pixel objects can be used by any code designed to work with Point objects.If a method expects a parameter of type Point, you can hand it a Pixel object and it just works.Polymorphism.
            Color color;//Extending by adding a field color
            public void clear() {
                        super.clear();//overriding point's clear() method.overriding is when same name and return type in the subclass.Here it looks into the superclass for the function.Looks into Point class. If not available then it looks into the superclass of Point.
                        color=null;
                        super.clear();//uses point's class implementation of the clear() method.
            }
}
class Run_Pixel{
      public void run(){
             Pixel newPixel=new Pixel();
                   newPixel.clear();
                   Object oref=new Pixel();
                          oref="Some String";//This perfectly valid
                   System.out.println(oref);
                   Point point=new Pixel();
                         point.clear();//uses Pixel's class implementation of the clear method.Invokes's actual class of the object(Pixel here) not the type of reference(Point).Compare with super.clear();
      }
}
//Classes that do not explicitly extend any other class implicitly extend the Object class.Object is the generic type for references that can refer to objects of any class
class Color{
}
//Objects are created using the new keyword, also known as instantiation, objects are often called instances
//Objects allocated under heap memory, All objects accessed via object references--any variable that may appear to hold an object actually contains a reference to that object.The types of such variables are known as reference types, in contrast to primitive types where variables hold values of that type. Object references null unless given to point to something
//The field in objects are known as instance variables, because there is a unique copy of the field in each object(instance) of the class.

//In imperative programming like C, structures are used. No access specifiers, no controlled access, very weak data abstraction
//In java abstractions are laid out in such a way that only interface is exposed to the user
class Numbers{
      private int num;//Private access specifier makes it visible only within the class.No access specifier means, accessibility within the package only
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
      /* private Card[] cards=new Card[DECK_SIZE];//Each card element in the array is implicitly initialized to null.An array's length is fixed when it is  created  and can never change.
    
       public void print(){
                   for(int i=0;i<cards.length;i++)//Array objects have a length field(bounds between 0 and n-1)
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
                    /*if(values==null |values.length==0)*///This code will attempt to access legth field even if values are null, which is an error.This can be corrected as follows:
                    if(values==null || values.length==0)//The conditional boolean operators evaluate their right hand operand only if the value s of the expressions has not already been determined by the left-hand operand. If values are null, no attempt is made to access the length field.
                            throw new IllegalArgumentException();
//The binary boolean operators --&, |, ^ are logical operators when their operands are boolean values and bitwise operators when their operands are integer values. The conditional-OR(||) and conditional-AND(&&) operators are logical operators and can only be used with the boolean operands. 
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
                System.out.println("The average is :"+newDeck.average1(a));//Remove the 1 to invoke the other function.

      }



}
//All array accesses are bounds checked(implicitly), to ensure that the index is in bounds else IndexOutOfBoundsException is thrown
//empty array:array.length=0;
//Methods should check that array reference is not null and also array length is not 0;Throw IllegalArgumentException otherwise.
//
//The modifier public and private are access modifiers because they control who can access a class, interface, field, or method.
//It may be necessary sometimes to have fields shared among all objects of that class.These shared variables are known as class variables--varibales specific tot he class as opposed to objects of the class.
//You obtain class-specific fields by declaring them static and they are therefore commonly called static fields
//you can have static methods, known as class methods.Can operate on static fields only(for non-static elements you need to send an object explicitly).
//Static method performs class releated operations/tasks and non-static methods perform object-related tasks.


//When a static method is invoked, there's no specific object for the method to operate on, and so no this reference.

//public static Point origin=new Point();  A class field, rather than an object field
//Named constants are declared static
//The Garbage collector:Unreferenced objects are automatically reclaimed by a garbage collector, which runs in the background and tracks object references
//package: a group of cooperating classes
//operations of a class are defined by its methods
//Hiding data behind methods so that it is inaccessible to other objects is the fundamental basis of data encapsulation
//A method can return only one value as a result.To return more than one value from a method, you must create an object whose purpose is to hold return value in a single unit and then return that object.

//this Reference:object's own reference(helpful in adding itself to a list of objects)
//this is a reference to the current(receiving) object.
//this reference can also be used to explicitly name the members of the current object.

//An array is a colection of variables all of the same type, accessed by simple integer indexes.
//Another set of collection type classes to store and retrieve objects in sequential manner:ArrayList and Vector in java.util package;

//import java.util.ArrayList;
class ArrayListExample{
      public void l(){
                  ArrayList List;//Unlike ststic array, the maximum number of elements as well as the type of the element to be added to this need not be known before.
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

//String Objects

class StringsDemo{
      void l(){
           System.out.println("Hello, World!");//The compiler creates a String object initialized to the values of the specified string literal and passes that String object as the argument to the println method.No need to specify the length of the string object when you create it.

           String myName="Maximus";//Create and initialize an string object
           myName=myName+" Lucius";//String concatenation, storing a reference back into myName
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
                System.out.println("Length of the above string is : "+myName.length());//Characters indexed from 0 to length()-1;
                System.out.println("Printing character by character : ");
                
                for(int i=0;i<=myName.length()-1;i++)
                     System.out.print(myName.charAt(i)+" ");
                System.out.println("\n");
                char ar[]=new char[myName.length()];//declaring an array of size of the string
                for(int i=0;i<=myName.length()-1;i++)
                     ar[i]=myName.charAt(i);      //Putting each character into an array
                String constructor_string=new String(ar);//making an string object, passing 'ar' as object argument
                System.out.println("Name = "+constructor_string);//printing the string object
              

                char k[]=myName.toCharArray();//change an string object to character array
                    for(int i=0;i<=myName.length()-1;i++)
                     System.out.print(k[i]+" ");//print character by character

                String x=new String(k);//making a string object with character arary k as argument
                System.out.println("\nName = "+x);
                //Comparing two strings
                   if(x.equals(myName)) 
                        System.out.println(x.equals(myName));
                    System.out.println(x==myName);//comparing if two references point to the same object(False in this case as these are two different objects even with the same value of the constructor).It does not check if both have the same contents.
//Strings are immutable. REpeated assignments may seem to change the string but every assignment gives a new value to the object reference and the original string remains unchanged.StringBuffer class provides for mutable Strings.
//String objects are not arrays of characters and you cannot assign an array of characters to a String reference.
//can construct a new String object from an array of characters by passing the arry as an argument to a String constructor. 
         }
}
class Run_BetterStringsDemo{
           public void run(){
                    BetterStringsDemo a=new BetterStringsDemo();
                       a.l();
           }
}


//EXTENDING A CLASS:Extend or subclass.Original class is known as superclass.The subclass can add new fields and methods ans so addd new behaviour.

//TYPE-CASTING:
/*class type_casting{
      public void t_c(){
                 String name="Petronius";                 
                 Object obj=name;
                 //name=obj;//Error.String is always an object, Object is not necessarily an object.
                  name=String(obj);//Correct.Type-Casted.This will be checked by the compiler first. If type casting fails(as java is a very strongly typed language) it will throw a 'ClassCastException'.
      }
}
*/
//Interfaces:Declare methods an object must support but not to supply the implementation of those methods.As long as behaviour meets certain criteria--called the contract--implementation details of the methods are irrelevant.These declarartions define a type, and any class that implements those methods can be said to have that type regardless of how the methods are implemented.

interface Lookup{//code that uses references of type Lookup(references to objects that implement the Lookup interface) can invoke find() methods.
          Object find(String name);
}
//All members of an interface are implicitly or explicitly, public--so they can be accessed anywhere the interface itself is accessible.
//An interface can extend one or more other interfaces, adding new constants or new methods that must be implemented by any class that implements the extended interface.
//A class's supertypes are the class it extends and the interfaces it implements, including all the supertypes of those classes and interfaces.So an object is not only an instance of its particular class but also of any of its supertypes,includinh interfaces.An object can be used polymorphically with both its superclass and any superinterfaces, including any of their supertypes.
/*class SimpleLookup implements Lookup{//References to SimpleLookup can invoke the find() method.
       private String[] names;
       private Object[] values;          

       public Object find(String name) {
              for(int i=0;i<names.length;i++)
                  if(names[i].equals(name))
                         return values[i];
              return null;
       } 
}
class SimpleLookup1{
       void processValues(String [] names, Lookup table) {
                 for(int i=0;i<name.length;i++) {
                    Object value=table.find(names[i]);
                      if(values!=null)
                          processValue(names[i],value);
                 }
       }
}*/

//EXCEPTIONS:An exception is an object, with type, methods, and data. Representing exceptions as objects is useful, because an exception object can inlcude data, methods, or both to report on or recover from specific kinds of exceptions.Exception objects are generally derived from the Exception class, which provides a string field to describe the error.All exceptions must be subclasses of the class Throwable, which is the superclass of Exception.

/*class BadDataSetException extends Exception{  }//define a new exception type BadDataSetException
class MyUtilities{
      public double getDataSet(String setName)
          throws BadDataException//A method can throw only those checked exceptions it declares--this is why they are called checked exceptions.
      {
          String file=setName+".dset";
          FileInputStream in = null;
          try  {
               in=new FileInputStream(file);
               return readDataSet(in);
          }
          catch(IOException e) {
               throw new BadDataSetException();
          }
          finally{
              try{
                  if(in!=null)
                     in.close();
              }
              catch(IOException e) {
                      ;
              }
          }
      } 
}
*/
//PACKAGES:Preventing Name Conflicts.Use Package prefix at the front of evry class, type, global function, and so on.Prefix conventions create naming contexts to ensure that names in one context do not conflict with names in other contexts.Packages are named and can be imported.Package names are hierarchial, with components separated by dots.can use fully qualified name or import all or part of the package.Importing instructs the compiler to look in  the package for types that it can't find defined locally.If two packages contain classes with same name, can use fully qualified class name for one or both of them.Import don't cause files to be "included" into the current file.

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
//import java.util.Date;At the top

class Run_Date1_Date2{
      public void run(){
             Date1 a=new Date1();//Java determines that Dtae type is actually java.util.Date type.
             Date2 b=new Date2();
                  a.l();
                  b.l();
      }
} 
//Two projects can still give their packages same name thus causing name collisions.Can be solved by some convention.
//for acme.com----package name would be: com.acme as in com.acme.tools;
//cant's import System.in.* so that we don't have to write it againg and again before the println method.System is a class, in which out is an static field whose type supports the println() method.

//whereas import java.util.Date; is a class or import java.util.*; Make sure that you are IMPORTING A TYPE


class Card{

}
