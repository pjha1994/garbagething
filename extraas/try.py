import urllib
import os
print(urllib.urlopen('http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/').read())
f=open('h.html','w')
f.write(urllib.urlopen('http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/').read())
f.close()
