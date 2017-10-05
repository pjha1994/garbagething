import re
from bs4 import BeautifulSoup
import os
import httplib2
def parse():
  # find ".html" or ".pdf" in a string
  match = re.compile('\.(pdf)')
  # parse page content
  s='http://bsw.iitd.ac.in/QuestionPapers/AM.php'
  lum=''
  lum1=''
  f=open(input('enter a file name\n'),'w')
  http = httplib2.Http()
  status, response = http.request(s)
  page = BeautifulSoup(response)
  # check links
  flag=1
  for link in page.findAll('a'):
     href = link['href']
     if re.search(match, href):
         #import webbrowser
         lum='http://bsw.iitd.ac.in/QuestionPapers/'+link['href']
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
  #l=l+1
  f.close()
parse()
