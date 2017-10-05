import re
from bs4 import BeautifulSoup
import os
import httplib2
def make_soup(s):
  http = httplib2.Http()
  status, response = http.request(s)
  page = BeautifulSoup(response)
  return page
def parse():
  f=open(input('filename?'),'w')
  f1=open('h.html','r')
  s='http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/'
  soup1=make_soup(s)
  match = re.compile('/courses/electrical-engineering-and-computer-science/')
  for link in soup1.findAll('a'):
     href = link['href']
     #print(href)#testing
     if re.search(match, href):
         k='http://ocw.mit.edu'+link['href']
         #print(k)#testing
         soup2=make_soup(k)
         for link in soup2.findAll('a'):
            match1 = re.compile('download-course-material')
            href1 = link['href']
            #print(match1,href1)#testing
            if re.search(match1,href1):
                lum1='http://ocw.mit.edu'+link['href']
                #print(lum1)#testing
                soup3=make_soup(lum1)
                for link in soup3.findAll('a'):
                   x=re.compile('\.(zip)')
                   if re.match(x,link['href']):
                      lum='http://ocw.mit.edu'+link['href']
                      print(lum)
                      f.write(lum)
                      f.write('\n')
  f1.close()
  f.close()
parse()

