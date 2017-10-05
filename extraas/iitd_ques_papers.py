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
  s='http://bsw.iitd.ac.in/ques.php'
  soup1=make_soup(s)
  match = re.compile('QuestionPapers')
  for link in soup1.findAll('a'):
     href = link['href']
     if re.search(match, href):
         k='http://bsw.iitd.ac.in/'+link['href']
         soup2=make_soup(k)
         for link in soup2.findAll('a'):
            match1 = re.compile('\.(pdf)')
            href1 = link['href']
            if re.search(match1,href1):
              lum='http://bsw.iitd.ac.in/QuestionPapers/'+link['href']
              print(lum)
              
parse()
