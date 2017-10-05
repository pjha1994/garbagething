import re
from bs4 import BeautifulSoup
import os
import httplib2
def make_soup(s):
   match=re.compile('https://|http://|www.|.com|.in|.org|gov.in')
   if re.search(match,s):
     http = httplib2.Http()
     status, response = http.request(s)
     #print(status, response)
     page = BeautifulSoup(response,'html.parser')
     return page
   else:
     return None
def is_a_valid_link(href):
   match1=re.compile('http://|https://')
   match2=re.compile('//i.4cdn.org/')
   return re.search(match1,href) and re.search(match2,href)
global D
D=set()
def parse(s):
    b=''
    c=0
    soup=make_soup(s)
    match=re.compile('\.(jpg|jpeg|png)')
    if(soup!=None):
        for link in soup.find_all('a',class_=['fileThumb']):
            a=link['href']
            x='http:'+a
            if(x!=b):
               #print(x)
               k = x
               k = k.split('/')
               k = k[4].split('.')
               D.add(int(k[0]))
               b=x
               
               
#def threads(s):
#   soup=make_soup(s)
#   for link in soup.find_all('a',class_=['replylink']):
#      parse('http://boards.4chan.org/s/'+link['href'])   
def read_images(s):
    #s='http://boards.4chan.org/s/thread/16887936/kiwi-girls-thread'
    #s = 'http://boards.4chan.org/s/thread/17630436'
    parse(s)
    #threads(s)
    #count=2
    #while(count<=):
     #  threads(s+str(count))
      # count=count+1
    for i in D:
       print(i)
#read_images()

import urllib.request

class AppURLopener(urllib.request.FancyURLopener):
    version = "Mozilla/5.0"

global Set
Set = set()
def print_thread_links(s):
    url = s
    #print(url)
    #content = urllib.request.urlopen(url).read()
    opener = AppURLopener()
    response = opener.open(url)
    soup = BeautifulSoup(response,'html.parser')
    
    for link in soup.find_all('a', {'class': 'replylink'}):
        k =  link['href'].split('/')
        Set.add(int(k[1]))
        #print (k[1])
    #for i in Set:
    #   print(i)


def getNumList():
   url = 'http://boards.4chan.org/s/'
   
   page =  2
   temp = url

   f = open('history.txt','r')

   history = set()

   for i in f:
      k = i.split('/')
      k = k[4].split('.')
      history.add(int(k[0]))
   f.close()

   
   for i in range(1):
      #print('page '+ str(k-1))
      try:
         print_thread_links(temp)
      except:
         #print('No page '+ str(k-1))
         break
      temp = url + str(page)
      page = page +1

      
   for i in Set:
       print(i)
       parse('http://boards.4chan.org/s/thread/'+str(i))
   print(len(Set))
   
   f = open('history.txt','a')
   for i in D:
      if(i not in history):
         print(i)
         f.write(str(i)+'\n')
   print(len(D))
   f.close()
#getNumList()

def l():
   import os
   f1 = open('temp1.txt','w')
   f2  = open('temp.txt','r')
   #x  = os.listdir('C:/Users/pjha/Desktop/4ch')
   for i in f2:
      if(i!='\n'):
      #print(i[0])
         f1.write(i)
   f2.close()
   f1.close()
l()
