

def m():
 # -*- coding: unicode -*-
 currency = u"$"
 print(ord(currency))
 # this is the first comment
 spam = 1  # and this is the second comment
 # ... and now a third!
 text = "# This is not a comment because it's inside quotes."
 print(spam)
 print(text)
 print('spam eggs')
 print('doesn\'t')
 print("doesn't")
 print('"Yes," he said.')
 print('"Yes," he said.')
 print('"Isn\'t," she said.')
 print('One line\nAnother line')
 print('One line\nAnother line')
 print('Unicode Lambda: \N{GREEK SMALL LETTER LAMDA}')
 #n
 price = 100.50
 price
 #price+_
 """
 print(u"Hello\u0020World !")
 print(ur"Hello\u0020World !")
 print(ur"Hello\\u0020World !")
 print(u"abc")
 print(u"abc")
 print(str(u"abc"))
 print(u "äöü")"""
 print(str(u"äöü"))
 #print(u"äöü".encode('utf-8'))
 #print(encode('\xc3\xa4\xc3\xb6\xc3\xbc', 'utf-8'))
 squares = [1, 4, 9, 16, 25]
 print(squares)
 print(squares[0])
 print(squares[-1])
 print( squares[-3:])
 print(squares[:])
 squares + [36, 49, 64, 81, 100]
 print(squares)
 cubes = [1, 8, 27, 65, 125]
 cubes[3] = 64
 print(cubes)
 cubes.append(216)
 cubes.append(7 ** 3)
 print(cubes)
 letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
 letters[2:5] = ['C', 'D', 'E']
 print(letters)
 print(letters[:])
 letters[:]=[]
 print(letters)
 print(len(letters))
 a = ['a', 'b', 'c']
 n = [1, 2, 3]
 x= [a,n]
 print(x)
 print(x[0])
 print(x[0][1])
 a, b = 0, 1
 while b < 10:
     print (b)
     a, b = b, a+b
 a, b = 0, 1
 while b < 10:
     print (b)
     a, b = b, a+b
m()
