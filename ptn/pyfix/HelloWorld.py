#Basic python data types
#Variables
#Integer Arithmetic: 



#----------------------------->Increasing Order of Precedence or barckets can change the Precedence
#    (+) (-) (*) (/) (//) (%) (**)
#----------------------------->Increasing Order of Precedence or barckets can change the Precedence


#No limit on length of integers
#5.0
#5. looks like the end of a sentence.
#Many different modules like 'math'
#from import math* will overwrite any function of the same name,safer to use import math
#can import a particular function 'from math import sqrt'

import math

def main(x):#Python uses ':' to mark end of if-else condition, loops, function defintions
    print(x)
main(input("enter a string    "))
print("32+56 = ",32+56)
print("5+9 = ",5+9)
print("22-6 = ",22-6)
print("12*14 = ",12*14)
print("22/7 = ",22/7)
print("2**4 = ",2**4)
print("25%7 = ",25%7)
print("1+2*3 = ",1+2*3)
print("(1+2)*3 = ",(1+2)*3)
print("7//3 = ",7//3)
print("3.8 + -43.2 = ",3.8 + -43.2)
print("12.6*0.5 = ",12.6*0.5)
print("12.6+0.01 = ",12.6+0.01)
print("365.0/12 = ",365.0/12)
print("8.8** -5.4 = ",8.8 ** -5.4)
print("5.6//1.2 = ",5.6//1.2)
print("5.6%3.2 = ",5.6%3.2)
print("2.3e02 = ",2.3e02)
print("3. = ",3.)
print("3.0 = ",3.0)
print(".5 = ",.5)
print("0.5 = ",0.5)
print("1/3 = ",1/3)
print("1j = ",1j)
print("1j*1j = ",1j*1j)
print("(-1+23j)*(1+55j) = ",(-1+23j)*(1+55j))
#print("math.sqrt(5) = ",math.sqrt(5))
#print("math.log(23) = ",math.log(23))
print("math.sqrt(5) = ",math.sqrt(5))#math can be removed from here by chnaging 'import math' to 'from import math*'
print("math.log(2+3) = ",math.log(2+3))
print("math.ceil(5) = ",math.ceil(5.56))
print("math.floor(4.3) = ",math.floor(4.3))
print("math.cos(5) = ",math.cos(5))
print("math.degrees(5) = ",math.degrees(5))
print("math.exp(5) = ",math.exp(5))
print("math.factorial(5) = ",math.factorial(5))
print("math.log(5) = ",math.log(5))#ln(value)
print("math.log(2,4) = ",math.log(2,4))#log(base,value)
print("math.pow(2,3) = ",math.pow(2,3))#pow(value,power)
print("math.radians(45) = ",math.radians(45))
print("math.sin(90) = ",math.sin(90))
print("math.sqrt(45) = ",math.sqrt(45))
print("math.tan(45) = ",math.tan(45))
print('This is String 1')
print("This is String 2")
print("""This is String 3""")
print('She said "Yes!"')#Single quotes containing double quotes
print("len (#Single quotes containing double quotes) = ",len("#Single quotes containing double quotes"))
print("len(#Single quotes containing double quotes) = ",len('#Single quotes containing double quotes'))
print("len(This is String 3) = ",len("""This is String 3"""))
print("5+len(This is String 3)*len(#Single quotes containing double quotes) = ",5+ len("""This is String 3""")*len("#Single quotes containing double quotes"))
print((len("house"+'boat'))*'12')
print('12'*len("house"+'boat'))
print(12*len("house"+'boat'))
print(dir(math))
print(dir(__builtins__))
help('string')
help()
print(math.tanh.__doc__)
print(bin.__doc__)
print(float(3))
print(float('3.2'))
print(float('3'))
print(str(85))
print(str(-9.78))
#There are implicit conversions in python as well.
print(25*8.5)#25 automatically converted to float
print(int(8.64))
print(round(8.5))
print(round(8.64))
print(int('5'))
print(float('5.1'))
print(math.trunc(5.1))
print(int('123'))
#pyhton keywords can't be variables
#else=23 is illegal
#variables start with letters/underscore
#python case sensitive
#when a value no longer has any variable poinying to it, Python automatically deletes it.
#Assignents don't copy
#Numbers and strings can't be chnaged, they can only be made another copy and then change.
M=23
m=4.6#python is case sensitive
x1=34
tax_rate=34
taxRate=32
Else=21
print(M*m*x1*tax_rate*taxRate*Else)
#Assignments as tuple
x,y,z=1,'two',"3"
print(x," ",y, " ",z )

x,y,z=(5,6,7) #TUPLES
print(x," ",y, " ",z )
#Swapping values
x,y,z=z,y,x
print(x," ",y, " ",z )

a,b=5,9
print(a,b)
#Swapping values
a,b=b,a

print(a,b)

#name.py
def foo():
    name=input('What is your first name?').strip()#strip trailing spaces
    print("Hello!"+name.capitalize()+'!')#capitalize the first letter and lower cased rest of letters
    name=input('Age : ').strip()
    print("Age : ",name)
foo()
print(dir(''))#seeing the format of string releated functions

print('     obnhj'.strip())#strip the trailing whitespace cahracter(s)
print('     obnhj')

#age.py
def calculate_age():
     name=input('What is your first name?')
     age=input('How old are you today?')
     age10=int(age)+10
     print('In 10 years you will be '*(age10)+'years old')#nOTICE THESE TWO PRINT STATEMENTS
     print('In 10 years you will be '+str(age10)+'years old')
     result = "Hello {}. You are {} years old".format(name, age)
     print(result)
calculate_age()

print(5+1%2)
print(5.0/3)
print(3*'5')
print(3*'5.0')


print('jack','ate','no','fat',sep='.')

#overriding the newline ending for print
#jack1.py
print('jack', 'ate ',sep='.',end='')
print('no', 'fat',sep='.')

print(eval(input('Type a mathematical expression>>>')))#eval(input(prompt))

#coins_short.py
#This program aska the user how many
#coins of various types they have,
#and then prints the total amount
#of money in pennies

#get the number of nicles,dimes,
#and quarters from the user
n,d,q=int(input('Nicles?')),int(input('Dimes?')),int(input('Quarters?'))

#calculate the total amount of money
total=5*n+10*d+25*q

#print the results
print()#print a blank line
print(str(total)+'cents')

#FLOW OF CONTROL
#BOOLEAN LOGIC
front_sensor_on=True

#bOOLEAN TABLE

p,q=False,False
i=0
while(i!=4):
  while(i!=4):
    print(p==q,p!=q,p and q, p or q, not p,sep='.')#Logical or is inclusive or because it includes the case when both are true
    q=not q
    i=i+1
  q=not q
  p=not p
#-------------------------------->Highest to lowest priotiy
# p==q | p!=q | not p | p and q | p or q
#-------------------------------->Highest to lowest priotiy

#Use brackets for complicated non-repeating logical operators (Not and(True or(False or Not))) 
#For repetitive use of an operator it is ok to omitt brackets TRue or false or ture or false or true
#Short-Circuit Evaluation:
       #p or q : if p false,then q,else p
       #p and q: if p false,then p,else q


#                  before_block
#                  if cond:
#                     true_block
#                  else:
#                     false_block
#                  after_block

#To indicate a block of code in python, you must indent each line of the block by the same amount(usually four spaces).
#Statements within the same  block of code need to be indented at the same level

#password1.py
def password(pwd):#if statement header
    if pwd=='apple':
       print('Logging in')
    else:                 #else not always necessary
       print('Wrong Log in')
    print('All done')
password(input("Enter the password \t"))#Can be formatted

#airfare.py
def airfare(age):
    if age<=2:
       print('free')
    elif 2<age<13:                  #Multiway decision: if-(...elif...)-else
       print('child fare')
    else:
       print('adult fare')
airfare(int(input("ENter an age \n")))

#Third type else-if

food=input("Favourite food")
reply='yuck' if food=='lamb' else 'yum'  #conditional if-else
print(reply)

#LOOPS: FOR and WHILE

#For loops: Variables automatically initialized
def forloop1(i):
  for  x in range(i): #for-loop header  #you can put a constant here #  0 to i-1
      print(x)
forloop1(int(input('Enter a number')))

def forloop2():
   for i in range(5,10):#Begins at 5 upto 9
      print(i)
forloop2()
def forloop3():
   for i in range(10):
       print(i+1)
forloop3()
def forloop4():
    for i in range(11):
        print(i)
forloop4()
def forloop5():
   for i in range(10,0,-1):
      print(i)
forloop5()
def forloop6():
   for i in range(10):
       print(10-i)
forloop6()

#while10.py
i=0
while i<10:
   print(i)
   i=i+1   #incrementer;not-necessarily in the body_block

#forfactorial.py
def forfactorial(n):
    fact=1
    for i in range(2,n+1):
         fact=fact*i
    print(str(n)+'  factorial is  '+str(fact))
forfactorial(int(input("Enter a number")))

#whilefcatorial.py
def whilefactorial(n):
    i=2
    fact=1
    while(i<=n):
       fact=fact*i
       i=i+1
    print("\n",str(n)+'  factorial is  '+str(fact))
whilefactorial(int(input("Enter a number \t")))

#forsum.py:Adding a known number of items

def forsum(n):
    s=0
    for i in range(n):
       x=int(input('Enter a number \t'))
       s=s+x
    print("sum of all the numbers is \t",s)
forsum(int(input('Enter number of numbers to sum \t')))

#whilesum.py:Adding an unknown list of numbers
def whilesum(): 
    s=0
    cond="Y"
    while(cond=="Y"):
       x=int(input('Enter a number \t'))
       s=s+x
       print('Again?','Y/n')
       cond=(input(''))
    print("sum of all the numbers is \t",s)
whilesum()
#Using break

def whilesum1():
    s=0
    while True:
        x=int(input('Enter a number \t'))
        s=s+x
        print('Again?','Y/n')
        cond=(input(''))
        if cond!="Y":
            break
    print("sum of all the numbers is \t",s)
whilesum1()

#for loops within a loop, the innermost loop to the break/continue statement will be effected only
#when continue is called inside a loop body, it immediately jumps up to the loop condition--thus continuing with the next iteration of the loop

#timestable.py
def timestable():
  for row in range(1,11):
    for col in range(1,11):
        prod=row*col
        if(prod<10):
            print(' ',end='')
        print(row*col,' ',end='')
  print()
timestable()


#FUNCTION:A reusable chunk of code
#Many ways to pass data into a function 

#Built in functions

print(pow(2,5))

#When you call a function within an expression, Pyhton essentially replaces the function call with its return value.
#pow(2,5)+8=32+8=40
#dir()---->Function with zero arguments

print(pow(0,0))

print(pow(3,4,5))#==(x**y)%z

print((3**4)%5) 

#print() has no return value
x=print('hello')
print(x)

#Reassigning function names:Helps re-writing built-in functions
dir=3
print(dir)
#dir()#It fails cause dir has been assigned the value 3 and hence dir() has disappeared

#area.py
def area(radius):     #function header #Function names follow the same rules as that of variables
    """Returns the area of a cirlce with
       -->the given radius
       For EXample:
       >>>   area(5.5)
          95.033177771091246
    """
    import math
    return math.pi*radius**2
print(area(int(input('Enter a radius \t'))))

print(area.__doc__)#Prints the documentation of the area() function

#DOCTEST

#if __name__ == "__main__":
#    import doctest
#    doctest.testmod()

#Functions with no return value is treated as if they ended with the line: return None

#Python supports FUNCTINAL PROGRAMMING in a very elegant manner:THe only change allowed is through the return statemen, near-complete banishment to side-effects
#When a function makes a change in any  way other than the returning value, we call that change a side effect.Printing to screen, writing to a file, play a song are all examples of side-effects

#To access global variable use 'global variable' else the local variable with same name will override the global one.

#global_correct.py
name='Jack'

def say_hello():
    print('Hello '+name+'!')
say_hello()

def change_name(new_name):
    name=new_name             #Will effect the local one
change_name((input('Enter a name to replace \t')))

say_hello()

def change_global_name(new_name):
    global name               #Will effect the global one
    name=new_name
change_global_name((input('Enter a name to replace \t')))

say_hello()

#MAIN function is entirely optional in Python whereas it is the part of languages like java,c++,c.

#Several kinds of parameters
#PASS BY REFERENCE:FUNCTION REFERS TO ORIGINAL PASSED VALUES USING NEW NAMES

#reference.py
def set1(x):
     x=1

def add(a,b):
    return a+b
x,y=3,4
print(add(x,y))#x---> 3 <---a
               #y---> 4 <---b

#Python doesn't support Pass by value.Copying may take very large time.

#DEFAULT PARAMETER VALUE
#No parameter with default value can appear before a parameter with one
#default parameters evaluated only once, the first time they are called
#greetings.py
def greet(name,greeting='Hello'):
    print(greeting,name+'!')
greet('bob')
greet('bob','Good morning!')

#Keyword parameters:Helps to understand the use of each parameter as well as calling irrespective of order
#It may be difficult sometimes to remember a long list of parameters and their order
#shopping.py
def shop(where='store',what='pasta',howmuch='10 pounds'):
    print('I want to go to the', where)
    print('and buy',howmuch,'of',what+'.')
shop()
shop(what='towels')
shop(howmuch='a ton',what='towels',where='bakery')

import this

#MODULES:Collection of programs in a .py file, not having a main program generally, used to write other programs, as a toolbox.To use a module you simply import it(import the file).Then you can call functions as module.function_name(arguments)
#Modules form namespaces, prevent name-clashes, support independent development
#However doing 
             #from jack import *
             #from sophie import *
#can still cause nameclashes as there is no way to specify the module now.This mechanism of importing everthing must be avoided.
#Can import everything at once 'from module_name import *'. Calling is simply by function name, no dot operator or module name.


#STRINGS:Aggregate Data Structure, provide first look at indexing and slicing, to extract substrings from strings
#Files are often treated as big strings

s='apple'
for letter in s:
   print(letter)
for i in range(5):
    print(s[i]) #s[5] will give out of range error.

#Negative indexing of STRINGS

for i in range(-5,0,1):# means -5 to -1
    print(s[i])
for i in range(-1,-6,-1):
    print(s[i])

#codesum.py
def codesum1(s):
    """Returns the sums of the character
       codes of s.
    """
    total = 0
    for c in s:
        total=total+ord(c)#ord(c) return an eqivalent integer for a chaarcter or eqivalent value for an 8-bit data string '\u2020'
    return total
print(codesum1((input('Enter a string to add its characters or an 8 bit string \t'))))

def codesum2(s):
    """Returns the sums of the character
       codes of s.
    """
    total = 0
    for i in range(len(s)):
        total=total+ord(s[i])#ord(c) return an eqivalent integer for a chaarcter or eqivalent value for an 8-bit data string '\u2020'
    return total
print(codesum2((input('Enter a string to add its characters or an 8 bit string \t'))))


#CHARACTER CODES
#ord() and chr() are reverse of each other, Assigned using unicode scheme
print(ord('a'))
print(ord('b'))
print(ord('c'))

print(chr(97))
print(chr(98))
print(chr(99))

#ESCAPE CHARACTERS:Can't be seen
print('\\')
print('\'')
print('\"')
print('\n')#\ doesn't count.-->len("\\") is 1
print('\r')
print('\t')

print(len('\n'))

#Windows uses \r\n for line endings..choose a good editor

#SLICING STRINGS:Extracting a substring
#s[begin:end]--> begin to end-1
#s[i:i+1]--->returns character at i
food='apple pie'
print(food[0:5])#--->returns 0 to 4 substring
print(food[6:9])#--->returns 6 to 8 substring


print(food[:5])
print(food[6:])
print(food[:])

print(food[-9:-4])
print(food[:-4])
print(food[-3:0])
print(food[-3:])

#extension.py
def get_ext(fname):
    """Returns the extension of file
       fname
    """
    dot=fname.rfind('.')
    if dot==-1:
       return ""
    else:
       return fname[dot+1:]
print(get_ext(input('enter a text file name with proper extension\n')))

#stringhandle.py
def stringhandle():
    s='ho_t'
    print(s.endswith('t'))#True when s endswith 't'
    print(s.startswith('h'))#True when s starts with 'h'
    print(s.isalnum())#True when s has only letters/numbers or both
    print(s.isalpha())#True if s contains only letters
    print(s.isdecimal())#True if s contains only decimal characters
    print(s.isdigit())#True if s contains only digits
    print(s.isidentifier())#True if s is a valid python identifier/name
    print(s.islower())#True if s contains only lower case letters 
    print(s.isnumeric())#True if s contains only numeric characters
    print(s.isprintable())#True if s contains only printable characters
    print(s.isspace())#True if s contains only whitespace characters
    print(s.istitle())#True if s is a title-case string
    print(s.isupper())#True if s contains only uppercase letters
    print('t' in s)#True if s contains 't' as a substring
    print(s.find('t'))#-1, or index where t starts in s
    print(s.rfind('t'))#Same as find, searches right to left
    print(s.index('t'))#Same as find, but raises value error if 't' is not in s
    print(s.rindex('t'))#Same as index, searches right to left
    print(s.capitalize())#s[0] made upper-case
    print(s.lower())#All letters of s made lower-case
    print(s.upper())#All letters of s made upper-case
    print(s.swapcase())#Lower case letter to upper case and vice-versa
    print(s.title())#Title-case version of s
    print(s.center(6,'e'))#Put numbers of characters already in 's'+number of additional characters you want,they get distributed evenly!
    s='apple'
    print(s.center(7,'e'))#center justified
    print(s.ljust(7,'e'))#left justified
    print(s.rjust(7,'e'))#right justified
    s='{} apple {}'
    print(s.format('hello','there'))#format
    s='what {} bitch'.format('UP')#format
    print(s)
    s='what {hek} bitch'.format(hek='the hell')#format, keyword parameters
    print(s) 
    s='apple'
    #for strips, whitespace characters are stripped by default
    print(s.strip('e'))#removes characters at the beginning or at the end
    print(s.lstrip('a'))#remove characters at the beginning only
    print(s.rstrip('e'))#remove characters at the end only
    print(s.partition('pp'))#String chopped in three pieces, partitioned by the given argument
    print(s.rpartition('p'))#Serches for the argument from the right end
    print(s.split('p'))#Returns list of substrings, separated by t
    print(s.rsplit('l'))#search starts from left
    print(s.splitlines())#list of lines in s
    s='Lets go go go, pepole'
    print(s.replace('go','no'))#Replace old substring with new substring
    print(s.replace('go',''))#Replace old substring with new substring
    print(s.expandtabs(5))#expand tabs with n space characters
    print(s.count('o'))
    #print(s.encode(UTF))#set encoding for s
    print(s.join('123'))
    s='pepole'
def stringhandle1():
    print(s.maketrans('people','bitchi'))#puts a one to one correspondence between characters, returns integer eqivalent list(TUPLE).Number of letters should be equal.
    x='people'
    y='bitchi'
    i=0
    j=0
    while((i < len(x)) and (j <len(y))):#eqivalent of for loops with two variables
           print(ord(x[i]),ord(y[j]))
           i=i+1
           j=j+1
    x=s.maketrans('people','bitchi')#Assigned the returned one to one correspondence list
    print(x)
    print(s.translate(x))#Makes replacement in s, using the translation table created by maketrans()
    print(s.zfill(10))#add 0s in the beginning of s
    leet_table=''.maketrans('EIOBT','31087')
    print('BE COOL. SPEAK LEET'.translate(leet_table))
    print('-85'.zfill(5))
    print(' '.join(['once','upon','a','time']))
    print('-'.join(['once','upon','a','time']))
    print(''.join(['once','upon','a','time']))


stringhandle()
stringhandle1()

#Difference between index and find is that the former returns ValueError if string not found while the latter returns -1.
#Find and index return the smallest index where the passed-in string starts,while rfind and rindex return the largest index where it starts.
#print(dir(''))...print all callable functions for a string


#REGULAR EXPRESSIONS:A*.A+,A?,A|B


import re
def is_done(s):
    return re.match('done|quit',s)
print(is_done(input('input a string')))


#DATA STRUCTURES



print(type(5))
print(type(5.0))
print(type('5'))
print(type(None))
print(type(print))#ROUGHLY SPEAKING, CLASSES AND TYPES ARE SYNONYMOUS

#Python lets you store values with different types in the same data structure
#can store number and string in same list
#java doesn't let you mix data types
#SEQUENCES:It is an ordered collection of values.Three built-in sequence types:strings,tuples and lists
#sequences share same indexing and slicing commands as for strings
#Sequences have following characteristics:
                                        #indexes: 0 to n-1
                                        #indexes:-1 to -n
                                        #seq[begin:end]:returns a sub-sequence from begin to end-1
                                        #same type of sequences can be conacatenated using + and *, can't conavatenate a tuple and a list
                                        #len(seq)
                                        #Check membership, x in s. s evaluates to TRue just when x is in the sequence s
                                        #strings and lists are most common type of sequences, tuples used very less common
                                        #seq[-1] returns last element of any sequence let it be a string, tuple, list.
                                        #Theoritically there is no limit to the length of a sequence
#TUPLES:An immutable sequence of 0 or more values. can contain any Python value--even other tuples

items=(-6,'cat',(1,2),())
print(items)
print(len(items))
print(items[-1])
print(items[1][0])

print(type(()))
print(type((5,)))#Trailing comma dictates TUPLE
print(type((5)))
print(type((1,2,3,)))#Trailing comma
print(type((1,2,3)))#Non-Trailing comma

#IMMUTABILITY: CAn't be changed. If change is required, a new seq must be created
            #Plus side:impossible to accidentially change, which prevent errors
            #Minus side:making smallest change requires copying the whole tuple, can led to memory wastage and leaks
            #LISTS must be preferrd for frequent modifications
lucky=(6,7,21,77)
print(lucky)
lucky2=lucky[1:]
print(lucky2)
print(lucky)

pets=('dog','cat','bird','dog')
print(pets)
print('bird' in pets)#returns TRue or False depending on whether the element is present or not
print(len(pets))#returns length of the tuple
print(pets.count('dog'))#number of times the element occurs
print(pets.index('dog'))#returns the index of first occurence of the element
print(pets.index('cat'))#raises error if not found

tup1=(1,2,3,)
tup2=(4,5,6)
print(tup2+pets+tup1+tup2)
print(2*tup1,2*tup2,2*pets)

#LISTS:Mutable.Add, remove, modify without making a copy.

numbers=[1,2,(3,),'hello',34]
print(numbers)
numbers2=numbers[1:]
print(numbers2)
print(numbers[2][0])

numbers=[1,2,(3,),'hello',34,[],[23,'string',[4]]]#no trailing comma for singleton lists in contrast with tuples
print(numbers)
print(len(numbers))
numbers2=numbers[1:]
print(numbers2)
print(numbers[2][0])
print(numbers+numbers)
print(numbers*3)
print(numbers[0])
print(numbers[1])
print(numbers[2])
print(numbers[1:3])
print(numbers[2:])
print(numbers[:-3])
#Lists can contain any kinds of values:numbers, strings or even other sequences
numbers[2]='hola' #MUTABILITY, replacement
print(numbers)
#elements of the list only point to their values(self-referential) and do not actually conatin them
snake=[1,2,3]
print(snake)
snake[0]=snake#Second element points to the entire list and not just the first element 
print(snake)#The [...] in output represents the self-referential list and does no go on printing continuously
snake.append([1,2,3,4])#Append the given list to the end
print(snake)
print(snake.count(2))#count the number of occurences of the element
snake.extend(snake)#Extend the list to the end
print(snake)
print(snake.index(3))#Returns the index value of the element
snake.insert(2,[1,2,3])#Insert(i,x)
print(snake)
print(snake.pop(0))#pops the ith element
print(snake.pop())#Removes element at the end
snake.remove([1,2,3,4])#removes the leftmost occurence of x, does not return the removed element
print("here ",snake)
snake.reverse()#reverses the order of the elements,moves the list pointers, reversal done in place
print(snake)
lst=['up','down','cat','dog']
print(lst)
lst.sort()#sort
#LEXICOGRAPHIC ORDER:Elements are ordered by their initial element, then their second element, and so on, general term for alphabetical order
print(lst)
lst.reverse()#Print sorted-reverse
print(lst)
pts=[(1,2,),(1,-1,),(3,5,),(2,1,)]
print(pts)
pts.sort()#Tuples and lists are sorted by their first element, then by their second element, and so on.
print(pts)
snake=[34,54646,46,456,45,256,42346,53,2]
snake.sort()#only one type of element must be present
print(snake)
lst=[]
lst.extend('cat')
print(lst)
lst.extend([1,5,-3])
print(lst)
#Every function except for count modifies the list

#numnote.py

def numnote(lst):
    msg=[]                         #Type the following in command line after compiling this file or this function separately 
    for num in lst:                   #for msg in numnote([1,2,3]):
        if(num<0):                           #     print(msg)
            s=str(num)+' is negative'            #OR
        elif 0<=num<=9:               #print('\n'.join(numnote([1,5,-6,3])))
            s=str(num)+' is a digit'
        msg.append(s)
    return msg
#numnote(x) Look for how to pass a list to a function. Or call it explicitly after interpretation, putting a list as parameter

#If push pop performed on the same list then it is referred as STACK, used in recursion nd undo

#LIST COMPREHENSIONS:Special notation for creating list

print([n*n for n in range(1,11)])
            #ELSE WITHOUT COMPREHENSION
result=[]
for n in range(1,11):
    result.append(n*n)
print(result)

print([2*n+7 for n in range(1,11)])
print([n**3 for n in range(1,11)])

print([c for c in 'pizza'])
print([c.upper() for c in 'pizza'])

names=['al','mei','jo','del']
print(names)
cap_names=[n.capitalize() for n in names]
print(cap_names)
print(names)

num=[-1,0,6,-4,-2,3]
print([n for n in num if n>0])
      #ELSE WITHOUT COMPREHENSION
result=[]
num=[-1,0,6,-4,-2,3]
for n in num:
    if n>0:
        result.append(n)
print(result)

#eatvowels.py
def eat_vowels(s):
    """Removes the vowels from s.
    """
    return ''.join([c for c in s if c.lower() not in 'aeiou'])#changes each character to lower case then matches with the vowels and then joined and returned
#Square brackets can be removed:Generator Expressions
print(eat_vowels(input('Enter a string to remove vowels from\n')))



#DICTIONARIES:Storing key:value pair, efficiently. Underlying Implementation using HASHING
#MUTABLE
#Order of elements in a dictionary cannot be guranteed
color={'red':1,'blue':2,'green':3}
print(color)
print(color['green'])
print(color['red'])
color['red']=90
print(color)
color['green']=-8
print(color)

#Key restrictions
                 #Keys are unique
                 #No duplicate keys, python will keep the last repeated value
                 #Keys are immutable,can't be a list/dictionary
                 #Values have no restrictions, are mutable, can appear as many times in a list
#DICTIOANRY FUNCTIONS

print(color.items())#A view of the complete key:value pair
print(color.keys())#A view of the complete keys only
print(color.values())#A view of the complete values only
print(color.get('red'))#get('key'), returns the corresponding value
print(color.pop('red'))#removes key and returns its corresponding value
print(color)
print(color.popitem())#pops some item and returns the pair
print(color)
print(color.clear())#clears the list
x=color.copy()
print(x)
color.fromkeys({'hola'},{90})#FIX THIS
print(color)
color.setdefault('do',5)
print(color)
e={'hola':1,'qwerty':34}
color.update(e)
print(color)
k=color.keys()
for i in k:
    print(i)
print(color.pop('hola'))
for i in k: print(i)

#SETS:Collections of 0 or more items with no duplicates, similar to keys with no associated values
#Sets are good way to remove duplicates from data collection, mimic efficiently the set operations like union, intersection.
#MUTABLE Sets and IMMUTABLE Frozensets
#Mostly used for removing duplicates froma data sequence

lst=[1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10]
print(lst)
#Order of elements not guranteed, just as in the case of ditionaries
print(set(lst))
x=set(lst)
print(x)

#print(dir(set()))

#INPUT AND OUTPUT

#String Interpolation
x=123
print('%.2f' %x)
print('%.89f'%x)
print('%.5f' %x)
print('%o'%x)#octal
print('%d'%x)#decimal
print('%x'%x)#lowecase hexadecimal
print('%X'%x)#uppercase hexadecimal
print('%e'%x)#lowecase float exponential
print('%E'%x)#uppercase float exponenetial
print('%F'%x)#Float
print('%s'%x)#String

print('%c'%x)#Character
print(ord('{'))#checking for the character
a,b,c='cat',3.14,6
s='There\'s %d %ss older than %.2f years' %(c,a,b)#%ss if for %s+s=cat+s
print(s)

#String formatting

s='My {pet} has {prob}'.format(pet='dog',prob='fleas')#Named Replacement
print(s)
s='My {0} has {1}'.format('dog','fleas')#Positional Replacement
print(s)

print('1/81={x}'.format(x=1/81))
print('1/81={x:f}'.format(x=1/81))
print('1/81={x:.3f}'.format(x=1/81))
print('num={x:.{d}f}'.format(x=1/81,d=3))
print('num={x:.{d}f}'.format(x=1/81,d=4))

#Type {{ for '{' and }} for '}}' or use r'STRING HERE', Raw string.

#Reading and Writing Files
#Files are collection of bits stored on a secondary storage
#TEXT FILES AND BINARY FILES
s='E:\\.Trash-1000\\files'#Using backslash twice
print(s)
s=r'E:\.Trash-1000\files' #Raw string
print(s)

#Examining files and folders
import os
print(os.getcwd())#Returns name of current working directory
print(os.listdir('C:\\'))#list of files and folders in the path
print(os.chdir('D:\\'))#sets the current working directory to this path
print(os.getcwd())
print(os.path.isfile(r'D:\rufus_files\syslinux-6.03\ldlinux.bss'))#returns true if filw with this name exists
print(os.path.isdir(r'D:\rufus_files\syslinux-6.03'))#returns true if folder name exists
print(os.stat(r'C:\Users\pjha\Desktop\HelloWorld.py'))#returns information about the fname specified

#list.py
def list_py(path=None):
    if path==None:
        path=os.getcwd()
    print( [fname for fname in os.listdir(path) if os.path.isfile(fname) if fname.endswith('.py')])
list_py()
print(os.getcwd())
print(os.chdir(r'C:\Users\pjha\Desktop'))
list_py()
print(os.chdir(r'C:\Users\pjha\Desktop\pyfix'))
def size_in_bytes(fname):
    return os.stat(fname).st_size

def cwd_size_in_bytes():
    total=0
    for name in os.files_cwd():
        total=total_size_in_bytes(name)
    return total
#cwd_size_in_bytes()  FIX THIS
#print(dir(os))

#PROCESSING TEXT FILES

#printfile.py

def print_file(fname):
    f=open(fname,'r')#r is reading(can be omitted), DEFAULT,open function returns a special file object, which represents the file on disk.
    for line in f:
        print(line,end='')
    f.close()#optional, deletes the file object, not the file itself
    
def print_file1(fname):
    f=open(fname,'r')
    print(f.read())
    f.close()
    
def print_file2(fname):
    print(open(fname,'r').read())
    
def write_file(fname):
    f=open(fname,'w')
    s=input('Enter the text')
    f.write(s)
    f.write(s)
    f.close()
    print_file2(fname)

def write_file1(fname):
    f=open(fname,'w')
    s=input('Enter the text')
    f.write(s)
    f.write(s)
    f.close()
    print_file(fname)
write_file1('k.txt')

def table(n):
    f=open('table.txt','w')
    for i in range(1,n+1,1):
        for j in range(1,11,1):
            f.write('{}*{} = {}\n'.format(i,j,i*j))
    f.close()
table(int(input('Enter a number to write the table\n')))

def table1(n):
    f=open('table1.txt','w')#OVERWRITES THE FILE
    i=1
    j=1
    while(i<=n):
        while(j<=10):
             f.write('{}*{} = {}\n'.format(i,j,i*j))
             j=j+1
        i=i+1
        j=1
    f.close()
table1(int(input('Enter a number to write the table\n')))
        
#TO AVOID OVERWRITING, CHECK FOR ITS EXISTENCE

#WRITE.PY
def make_story(fname):
    if os.path.isfile(fname):
        print('File {} already exists'.format(fname))
    else:
        f=open(fname,'w')
        f.write('\nhi there\n')
        f.close()
make_story(input('Enter a file name .txt'))

def add_to_story(line,fname='story.txt'):
    f=open(fname,'a')
    f.write(line)
    f.close()
add_to_story(input('enter a line to append'),'r.txt')

#Inserting a string at the beginning of the file

def insert_title(title,fname='story.txt'):
    f=open(fname,'r+')#File can both be written and read
    temp=f.read()#Read entire file as a string
    temp=title+'\n\n'+temp#Append the title at the beginnignof the string
    f.seek(0)#Reset the internal pointer. After f.read the pointer goes to the end of file. Putting it back to 0 resets it.
    f.write(temp)#Write the text
    f.close()#Close the file
insert_title(input('Enter the title\n'))#Enter the title
print_file('story.txt')#Print the entire file

#If a file is not text, then it is considered binary file;opened in 'b' mode;access individual bytes

def is_gif(fname):
    f=open(fname,'br')#binary reading mode
    first4=tuple(f.read(4))
    return first4==(0x47,0x49,0x46,0x38)#checking first four bytes of a file
print(is_gif('story.txt'))

#Reading a binary file:f.read(n);reads next n bytes;binary files use pointers to keep track of which byte should be read next int he file

#Pickling:convenient way to deal with binary files;this module lets you easily read and write almost any data structure.
import pickle
def make_pickled_file():
    grades={'alan':[4,8,10,10],
            'tom':[7,7,7,8],
            'dan':[5,None,7,7],
            'may':[10,8,10,10]
            }
    outfile=open('grades.dat','wb')
    pickle.dump(grades,outfile)#PICKLE.DUMP
make_pickled_file()
def get_pickled_data():
    infile=open('grades.dat','rb')
    grades=pickle.load(infile)#PICKLE.LOAD
    return grades
print(get_pickled_data())

import webbrowser
#webbrowser.open('http://ww.yahoo.com')  include print here; This will open the web browser
def reading_web_pages():  #fix this function
    import urllib.request
    resp=urllib.request('http://www.python.org')
    html=resp.read()
    print(html[:25])


#Exception Handling:Dealing with unexpected errors|
#Raise an exception-->Catch-->Handle the error|
#Executing clean-up code wheteher or not an exception is raised|
#Like IOError

#open('unicorn.dat')#FileNotFoundError

#Python immediately halts the program and outputs a traceback which is a list of functions that were called before exception occurred
#when exception occurs, we say it has been raised, or has been thrown
#Not doing anything with the thrown exception halts the program showing traceback or stack trace
#We should cath and handle exceptions

#print(1/0)#ZeroDivisionError

#x:=5#syntax error
#print('hello world)#EOL error

#raise IOError('This is a test!')#OSError
#raise OSError('This is also a test')
#Two options with exceptions:
                           #1:Ignore exception and let your program crash with a traceback
                           #2:Catch exception, print a friendly message or fix the exception

def get_age():
    while True:
        try:
            n=int(input('How old are you?'))
            return n            #Return statement skipped when an exception raised
        except ValueError:      #Type of error can be figured out by doing command line experiments
            print('Please enter an integer value')
print(get_age())
#IF-else statements evaluate booleans:Try-except evaluates exceptions
#Can raise multiple exceptions or one exception multiple times
#CATCHING MULTIPLE EXCEPTIONS
def convert_to_int(s,base):
    try:
        return int(s,base)
    except (ValueError,TypeError):
         return 'error'

def convert_to_int(s,base):
    try:
        return int(s,base)
    except ValueError:
        return 'value error'
    except TypeError:
        return 'type error'
#Catching all exceptions
def convert_to_int(s,base):
    try:
        return int(s,base)
    except:
        return 'error'
#Clean-up Actions
def invert(x):
    try:
        return 1/x
    except ZeroDivisionError:
        return 'error'
    finally:             #f.close() statements should be under finally.A file must me closed whether IOError occurs or not
        print('invert(%s)done'%x)
def without_with(fname):
    num=1
    f=open(fname)#its uncertain when will the file be closed;may create issues with other program trying to acccess the same file
    for line in f:
        print('%04d %s '%(num,line),end='')
        num=num+1
        
def with_satement(fname):
    num=1
    with open(fname,'r') as f:#With statement closes the file as soon as for loop stops executing
        print('%04d %s'%(num,line),end='')
        num=num+1
#print('{0:04} {1}'.format(num,line),end='')
        
#OBJECT-ORIENTED PROGRAMMING:Methodology for organizing programs encouraging careful design and reuse
#Practical way to structure and create large programs
#Numbers,strings,lists,dictionaries,files and functions are all example of objects
#Need a class:A blueprint for creating an object of a particular kind.(Data+Functions)
#An object encapsulates both the data and functions that operate on that data
#Inheritance:Inherit data and functions, reusability of code.
#Polymorphism:A suitable function is called depending on the type of object passed at runtime

#Writing a Class
#person.py
class Person:
    """Class to represent a Person"""
    def __init__(self):  #Standard function to initialize object values,Python automatically calls this function on object creation
        self.name=''
        self.age=0
    def display(self):
        print("Person({},{})".format(self.name,self.age))
p=Person()#creates new object return new object of type person
#function defined inside a class is called a method
#'self'(without quotes) must be methods' first parameter
#'self' automatically added by python to all objects:Points to object itself and lets functions within the class unambiguously to the data and functions within the object
#Can replace self with any other name
#Objects can be used as data types
#Variables not beginning with an underscore are called public varibales-->Ant code can access them
#Always make object variable private
#No setters make the objects immutable
                 

#person.py
class Person1:
    def __init__(self):  #Standard function to initialize object values,Python automatically calls this function on object creation
        self.name=''
        self.age=0
    def display(self):
        print("Person({},{})".format(self.name,self.age))
    def __str__(self):   #Special str method is used to generate a string representation of an object
        return "Person('{}',{})".format(self.name,self.age)

    
class Person2:
    def __init__(self,name='',age=0):  #Standard function to initialize object values,Python automatically calls this function on object creation
        self._name=name                 #name and age arguments should be passed during initialization
        self._age=age                   #Default parameters should be avoided
    def display(self):
        print(str(self))
    def __str__(self):   #Special str method is used to generate a string representation of an object
        return "Person('{}',{})".format(self._name,self._age)
    def __repr__(self):   #Make represenation of object easy/simple(just type the object name on cmd)
        return str(self)
    def display1(self):   #Its often not necessary to write diplay() method
         print(self)
    def set_age(self,age): #Setter
        if 0<age<=150:
            self._age=age
    def get_age(self):      #Getter
         return self.age
    @property               # '@' To indicate its a getter
    def age(self):
        """Returns this person's"""
        return self._age
    @age.setter       #Setter-Decorator:use p.age=45. It calls 'age 'function now
    def age(self,age):
        if 0<age<=150:
            self._age=age
p._age=56  #Illegal
#change every self._age to self.__age to indicate its a private variable and can't be accessed
#p._Person.__age=879#Illegal(accesing the private variable)
#Helps to remove the possibility of accidental change

#INHERITANCE:Creating new classes from the existing one and adding attributes
#POLYMORPHISM:
#OVERRIDING FUNCTIONS

