import re
from bs4 import BeautifulSoup
import os
import httplib2
def parse():
 import urllib.request
 # find ".html" or ".pdf" in a string
 match = re.compile('\.(pdf)')
 # parse page content
 m=8827
 s='http://dspace.cusat.ac.in/jspui/handle/123456789/'
 #s='http://hdl.handle.net/123456789/'
 l=8770
 i=87730
 #flag=1
 lum=''
 lum1=''
 f=open(input('enter a file name'),'w')
 while(l<=m):
  x=s+str(l)
  http = httplib2.Http()
  status, response = http.request(x)
  page = BeautifulSoup(response)
  # check links
  flag=1
  for link in page.findAll('a'):
     href = link['href']
     if re.search(match, href):
         #import webbrowser
         lum='http://dspace.cusat.ac.in/'+link['href']
         #webbrowser.open(lum)
         if(flag==1):
             print (lum)
             f.write(lum)
             f.write('\n')
             lum1=lum
             flag=5
         if(lum!=lum1 and flag!=1):
            print (lum)
            f.write(lum)
            f.write('\n')
            flag=1
  l=l+1
 f.close()
parse()
