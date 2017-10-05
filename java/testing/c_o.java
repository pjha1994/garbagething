//2.CLASSES AND OBJECTS
//class is the fundamental unit.Provide structure for objects.Define methods which manipulate the data stored in objects.Methods provide behaviour of class.
//Separates "what" and "How". 
//Methods define the "what".This combination of methods,data and semantics is often described as contract between the desiginer of the class and the programmer who uses it.This contract defines a type such that all objects that are instances of that type are known to honor that contract.
//The contract of the method, both signature and semantics together, define what it means.
//"How" of an object is defined by its class, which dfines the implementation of the methods the object supports.An object can use other objects.
//Fundamental of a programming language is to manipulate the data to get useful information.The actual memory allocation for the object of class is provided through instantiation using new operator.The handle(of the object) to that memory location is called object reference.
//OBJECT = DATA + {OPERATIONS}
//METHODS AND FUNCTIONS:Methods are bound to the data within the object whereas the functions are freely available in the working programming environment.We access and update the data that resides in that class object only through the object reference(except for ststic fields and methods).
//interactions between objects allowed by one object holding the reference of the other(passing as arguments)
//YOU CAN HAVE SEVERAL MAIN CLASS IN DIFFERENT CLASSES CONTROLLING DIFFERENT SEGMENTS OF THE CODE.Save the file in any_name.java format.Compile this file.Then run using java any_main_class_name.This will generate different results on given different class names which contain main.
/*
                             Student Ramesh=new Student(...);
                                //Student object instantiated with the reference Ramesh.
                      
                             Teacher Prakash=new Teacher(...);
                                //Teacher object is instantiated with the reference name Prakash.
                            //Dots in parentheses represent attribute list of respective classes;

                            Praksh.fillMarks(Rames,89.5);//Teacher assigns 89.5 marks to a particular student "Ramesh"

                            //A code fragment of fillMarks in teacher class:
                             
                            void fillMarks(Student s, float marks)
                            {s.setMarks(marks);}                        


 

//Excecution of  a program may be understood  througha logical structure with the help of data structure called a directed graph.An object-oriented program under execution can be thought of as this graph with the individual objects as nodes in the graph and the actual communication paths(also known as messages) as edges of te graph.In the fashion, one object interacts with the other through these message edge, and the computation and the updated data propagates across the graph during the program execution.


//Characteristics of an object:Attribute Section(set of type declaartions) + Method Section(functionality for the class)
                             //State-->determined by actual values of individual types residing in it after creation of the object.The fact that every object has a state implies that every object consumes certain amount of memory.
                            //Behaviour-->Functionality defined inside the class represents the class behaviour.Functionality describes how an object responds operations in terms of its state updations and message passing.(Methods:Only certain operations valid)
                           //Identity-->Objects are separate individuals.Each object has its own identity.(Differ by physical memory)
//Methods that return values:accessors/get methods.
//Methods that updates existing values:mutators/set methods.
//Use Private access specifier for data fields.Can be accessed through public ACCESSORS.
//A class can even have a method with the same name as that of class.If no return type then it a constructor else its a function.This is how compiler makes a difference between a constructor and  a function with the same name as that of the class.
                                                 ---------------------------
                                                 |         Student         |
                                                 ---------------------------
                                                 |Name:String              |
                                                 |Age:int                  |
                                                 |IDNo:String              |
                                                 |Institute:String         |
                                                 |Course:String            |
                                                 |                         |
                                                 ---------------------------
                                                 |   <Method Section>      |
                                                 ---------------------------
*/
//There can be nested classes and nested interfaces that occur nested within the declaration of another class or interface.
//CLASS MODIFIERS:Prefixes to classes:
                                     //Public:Else accessible only in its own package
                                     //abstract:incomplete classes.can't be instantiated.method implementations given by subclasses.
                                     //final:A final class can't be subclassed.
                                     //strict floating point:A class declared strictfp has all floating point arithmetic, defined within the class, evaluated strictly.

//FIELD MODIFIERS:
                 //access modifiers
                 //static-->Within in own class, static field can be accessed directly but outside it should be accessed by class_name.class_variable_name;Like Body.nextID; System.out accesses static out field;
//A static member may also be accessed via areference to an object of that class; Like mercury.nextID-->it should be avoided.
//It is the type of reference, not the type of the object it refers to, that determines the class to look in for the static variable.The reference can even be null.
                 //final-->variable whose value can't be changed once initialized, any attempt to chnage the value will produce a compile-time error.Used for named constants.Used to define an immutable property of a class or object--a property that does not change for the lifetime of the class or object.If no initializer for the field then it is called BLANK FINAL.
//BLANK FINAL fields must be initialized once the class has been initialized (for static final fields), or once an object of the class has been fully constructed.Complier will refuse if the final does not get initialized. 
                 //transient--relates to object serialzation
                 //volatile--relates to synchronization and memory model issues
//A field cannot be both final and volatile.

//A class cannot be both final and abstract.A class eclaration cab be preceded by several modifiers, in any order, but follow the above order.
//There can be only one public class per file and that should be the file name as well.(Try this out)
//instance variables belongs to each object.
//class variables, like static, belong to class only and shared by each object.Only one instance of that field exists.
class Body{//Class declaration, creates a type name.
    public long idNum;//Fields,initialization optional.Here it is default value.
    public String name="<unnamed>";//-----------------------------------|
    public Body orbits=null;//Reference to another Body field.----------|
                                                                      //|--------->Explicit Initializer
    public static long indexID=0;//initialized to 0.--------------------|
    Body(){//-------------------------------->Constructor initialize
       idNum=indexID++;//For this idNum can be made private.Then it should also be removed from 	Run_Body where it is being accessed directly.
    }
    Body(String bodyName) {
         this(bodyName,null);
    }
    Body(String bodyName, Body orbitsAround) {
                this();//One constructor can invoke another constructor.It invokes Body().EXPLICIT CONSTRUCTOR INVOCATION.mUST BE the first statment if necessary.
                name=bodyName;
                orbits=orbitsAround;
    }
    Body(Body other) {//this constructor takes an argument of the current object type and constructs the new object to be a copy of the passed in object.However preferrred way is clone method.
       idNum=other.idNum;
       name=other.name;
       orbits=other.orbits;
    }
    public String toString() {//Try hiding this code in comments and see the output.
          String desc = idNum + "("+name+")";
          if(orbits!=null)
             desc+="orbits"+orbits.toString();
          return desc;
    }
//All objects have a toString method whether their class explicitly defines one or not--this is because all classes extend the class Object and it defines toString method.
}
//Constructors can also be declared to throw checked exceptions.The throws clause comes after the parameter list and before the opening curly brace of the constructor body.
//Any expressions that are used as argumrnts for the explicit constructor invocation must not refer to any fields or methods of the current object---to all intents and purposes ther is no current object at this stage of construction.
//Constructors can have any of the same access modifiers as class memebers, but constructors are not members of a class--a distinction can be ignored, except whn it comes to inheritance.
//If no you don't provide a no-argument constructors of any kind in a class, the language provides a default no-arg constructor that does nothing, called default-constructor.If you gave with-argument constructors then you should also provide  the default constructor explicitly.
//Default constructor has the same accessibility as the class for which it was defined--if the class is public then the default constructor is public.
//COPY CONSTRUCTOR:Takes an argument of the current object type and constructs the new object to be a copy of the passed in object.
class Run_Body{
    public void run(){//Method(s)
          Body mercury;//A reference of Body type.It doesn't create object.It can hold a reference to an object of type body.May refer to any number of Body objects.These objects must be explicitly created.
          Body sun=new Body();//JVM returns reference to the new object.
          sun.idNum=Body.indexID++;//nextID is a unique identifier to each object.
          //sun.nameFor="Sol";
          sun.orbits=null;
          Body earth=new Body();
          earth.idNum=Body.indexID++;
          earth.orbits=sun;

    }
}
//An initializer(like in indexID field) could be another field,a  method invocation or an exression or a combination of these.The final value should be of the right type an functions must not throw an exception.
class field_initialization{
     double zero=0.0;
     double sum=4.5+3.7;
     double zeroCopy=zero;
     double rootTwo=Math.sqrt(2);
     double someVal=sum+2*Math.sqrt(rootTwo);
}
//INITIALIZATION BLOCK:A block of statements that appears within the class declaration, outside of any memeber, or constructor, declaration and which initializes the fields of the object.
class c_o{
    public static void main(String [] args) {
               Body sun=new Body("Sol",null);
               Body earth=new Body("Earth",sun);
               System.out.println("Body "+earth.name+" orbits "+earth.orbits.name+" and has ID "+earth.idNum);
               System.out.println("Sun "+sun);//This statement implicitly calls toString() method.
               System.out.println("Earth "+earth);
    }
}
/*class Body1{
    public long idNum;
    public String name = "<unnamed>";
    public Body orbits=null;
    
    private static long nextID = 0;
    
    {//This is an initialization block.
    idNum=nextID++;
    }
//Now the two-argument constructor doesn't need to perform the explicit invocation of the no-arg constructor, but we no longer have a no-arg constructor and so everyone is forced to use the two-argument constructor.
//Initialization is the purpose of having initialization blocks, but in practice you can make it do anything--the compiler won't check what it does.It is executed as if it were placed at the beginning of every constructor in the class--with multiple blocks being executed in the order they appear in the class.An initialization block can throw a checked exception only if all of the classes constructors are declared to throw that exception.
    public Body(String bodyName, Body orbitsAround)
    {
    name=bodyName;
    orbits= orbitsAround;
    }
}*/
//STATIC INITIALIZATION BLOCK:Similar to non-static initialization block except it is declared static, can only refer to static memebers of the class and cannot throw any checked exceptions.
/*class Primes{
     static int [] knownPrimes = new int[4]; 
     
     static {
          knownPrimes[0]=2;
          for(int i=1;i<knownPrimes.length;i++)
               knownPrimes[i] = nextPrime();
     }
     public int nextPrime(){return 1;}//It has to be fixed.
}*/
//The  order of initialization within a class is first-to-last---each field initializer or initialization block is executed before the next one, from the beginning of the source to the end.The static initializers are executed when the class is loaded.With this gurantee, our static block in the example is assured that the knownPrimes array is already declared before the initialization code block executes.Anyone accessing a static field is guranteed that the field has been initialized.
/*
                                                ------------------------------------------------------
                                                |     INITIAL VALUES OF UNINITIALIZED FIELDS:        |
                                                ------------------------------------------------------     
                                                |Type                  |               Initial Value |
                                                ------------------------------------------------------
                                                |boolean               |                 false       |
                                                |char                  |                 '\u0000'    |
                                                |byte,short,int,long   |                 0           |
                                                |float                 |                 +0.0f       |
                                                |double                |                 +0.0        |
                                                |object reference      |                 null        |
                                                ------------------------------------------------------
*/

//OOP supports encapsulation and data-hiding:Using classes and Access control/Access modifiers.
//All members of a class are always visible to the code in the class itself.
//Class members have 4 possible access modifiers:
                                                //private:members accessible only inside the class.
                                                //package:memebers with no access specififers tot he classes in same package and in the class itself.
                                                //protected:accessible in subclasses, in the classes in the same package, and in the class itelf
                                                //Public:accessed anywhere the class is accessible.

//Private and protected apply only to memebers not to the classes or interfaces themselves(unless nested).
//If no space for allocating objects, run garbage collector and if not solved then throw OutOfMemoryError exception.
//Object created using new but never deleted that way.
//If necessary, set the references to null and the memory will be reclaimed.
//Constructors used for not-so-simple initialization.Constructors are invoked after instance variables of a newly created object of the class have been assigned their default initial values and after their explicit initializers are executed.After constructo executed, a reference is returned.
//OOP has key features like abstractioin, encapsulation and information hididng.
//To achieve the above features in imperative languages like C, we construct Abstract Data Types (ADTs) using structures and pointers and organize our code in multiple files.We use separate compilation.
//class interface should look coherent.
//A method declaration consists of two parts: the method header and the method body.The method header consists of a set of modifiers, the method return type, signature and a throws clause listing the exceptions thrown by the method.The method signature consists of the method name and the(possibly empty) parameter type list enclosed in parantheses.Modifiers and throws clause are optional.
//METHOD MODIFIERS:
                  //ACCESS MODIFIERS:
                  //ABSTRACT: body not defines in the current class, ends with a semicolon only.Subclass is responsible for providing a body for this method.An abstarct method cannot be static,final,synchronized,native, or strictfp.
                  //Static:invoked on behalf of an entire class, not on a specific object instantiated from that class.Such methods are known as class methods.might perform general task for all objects.Can access only static fields and other static methods.Because non-static emembers have to be accessed via an object reference, and there is no object reference available within the static method--there is no 'this' reference.
                  //Final:CAN'T BE OVERRIDDEN IN ASUBCLASS.
                  //Synchronized:
                  //NATIVE
                  //Strict Floating Point:a method declared strictfp:If the class declared strictfp then method is implicitly strictfp.
//Can't declare methods with avriable number of parameters--though you can declare a method with an array of objects as a parameter.
//A method completes execution in any of the three cases: a return is executed, end of method is reached or an uncaught exception is thrown.
//Can return either a primitive type or an object reference.
//For more than one return values:
                                 //return references to objects that store the results as fields
                                 //take one or more parameters that reference objects in which to store the results
                                 //Return an array that contain results.
//Returns should be assignable value to a variable of the declared return type, or else throw an exception.
//All classes extend Object.This can be areturn type if in DOUBT.

//PARAMETER VALUES:All primitive types are passed by value;
                  //when parameter is an object reference, the object reference--not the object itself--is what is passed by "by values".You can change which object a parameter refers to inside the method without affecting the reference that was passed.If you change any fields of the object or invoke methods that change the object's state, the object is changed for every part of the program that holds a reference to it.                    
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
     public static void commonName(Body bodyRef) {
            bodyRef.name = "Dog Star";
            bodyRef=null;//Referred to null but the object still exists in main();Change made is still viisble in main's sirius.
//This isn't pass by reference.Java doesn't support pass by reference.
//Pass By Reference:means that when an argument is passed to a function, the invoked function gets a reference to the original value,not a copy of its value.If a function modifies its parameter,the value in the calling code will be changed because the argument and parameter use the same slot of memory.
//Java has only pass by value.It passes object references by value.Because two copies of same reference refer to the same actual object, changes made through one reference variable are visible through the other.
     }
}
//Making a field final or private are two different things.One refers immutability while the other refers to accessibility.
//If a field is immutable then it must be final, regardless of accessibility
//If a field is to be a part of contract, it should be made private regardless it is final or not.
//PER-CLASS ACCESS CONTROL


//this-->Available inside a non-static method.There is no this reference inside a static method because there is no specific object to operate on.The this reference is most commonly used as a way to pass a reference to the current object as an argument to other methods.
                               //service.add(this)
                         /*
                           public void capcture(Body victim) {//Method inside Body class uses this.
                                    victim.orbits = this;
                           }
                           public Body(String name, Body orbits) {//Local variables hides the object variables.
                                    this();
                                    this.name=name;
                                    this.orbits=orbits;
                           }
                         */

//OVERLOADING METHODS:Same name and return type but different argument list.compiler matches the number and type of arguments, to find the best match.THey must have different signature.Signature doesn't include return type or the list of thrown exceptions.Constructors can also be overloaded.
//cmd arguments to main method in class echo:
                             //java echo in here...//name of class is not included into the string arguments.
//Here java is java Bytecode interpreter.invokes echo.main with the cmd arguments.
//An application can have any number of main methods because each class in the application can have one.Only one main is used any given time you run a program.The main that's actually used is sppecified when the program is run(Keep changing class names in cmd and other classes' main will be executed).
//Native Methods:lets you implement a method that can be invoked from the java programming language but was written in a "nature", usually c,c++.
                                       //public native int getCPUID();
//A native method can be overloaded, overridden, final, static, synchronized, public, protected or private.A native method cannot,however, be declared abstract, nor strictfp.All portability and safety is lost on using native methods.Implemented using an API.

//CLASS DESIGN ISSUES:
/*
                     ***Attributes and method definitions:Two types of attributes/fields, static and non-static.static declarations are class fields.non-static fields are instance fields.Each instance has individual allocation for each object.static are alloted only once and shared throughout the lifetime of the program.
                               static int count;
                     Methods are not freely available in Java, unlike C.We invoke methods through object reference.
                     Static methods are like are like C functions.Provide this flxibility of direct access by just referring to
                     their class names without creating objects of the respective classes.That's why they are called class methods.
                                           Integer.parseInt():parseInt() is a static method or class method of class Integer.
                      ***Naming Conventions:           
                                        constants value-->static final double PI=3.14;//Caps and underscore.static and final.
                                        Accessor:getmethod
                                        Setter:setmethod
                                        class name begins with caps. 
                                        all the methods should not be public, if it isn't absolutely necessary.
                      ***Design of Accessor and Mutator Methods:Not necessary to initialize all the fields through a constructor.
                                                                Lazy initialization through mutators can be done.
                      ***Separation of accessors and mutators:One should be careful, particularly when the accessor 
                                                              returns an object reference which is mutable.
                                                              Be careful when returning references which have mutators available to them.
                                                              It is not mandatory that a class must contain accessor and mutator methods.
                                                              Return cloned objects.Return copies instead of actual references.In that case
                                                              though references are mutable but does not affects the original value.
                                                              Implementation aspects pertaining to cloning of objects will be discussed
                                                              separately.
                      ***Documentation:include comments, short description about the functionality in terms of preconditions and postconditions.
                                       easier to understand and debug.Easy to enhance the functionality.To generate API documentation.
                                       --->Double slashes(//):a one line comment
                                       --->C style comments():Multiple lined comments
                                       --->Doc comments():
                      ***Class Invariance:Certain property remaining same before and after the execution of the code, it may get violated 
                                          during the execution of the code.Those violations are hadled as warnings and exceptions eparately. 
*/
//Integers and chars can't be assigned to objects directly and hence has to be converted into objects using wrapper classes.Java being strongly typed.
