import re
from bs4 import BeautifulSoup
import os
import httplib2
def make_soup(s):
  http = httplib2.Http()
  status, response = http.request(s)
  page = BeautifulSoup(response)
  return page
def parse_reddit():
    b=''
    s='https://www.reddit.com/r/spaceporn/'
    soup=make_soup(s)
    #match=re.compile('title may-blank loggedin')
    match1=re.compile('\.(jpeg|jpg|png)')
    #for link in soup.find_all('a', {'class':['title may-blank loggedin']}):
    for link in soup.find_all('a', {'class': ['title', 'may-blank', 'loggedin']}):
        #soup.find_all('a',class_='title may-blank loggedin'):
      if re.search(match1,link['href']):
        a=link['href']
        if(a!=b):
          print(a)
          b=a
        else:
         i=0
         for link in soup.find_all('a',{'rel':['nofollow', 'next']}):
          soup1=make_soup(link['href'])
          for link in soup1.find_all('a', {'class': ['title', 'may-blank', 'loggedin']}):
            if re.search(match1,link['href']):
              a=link['href']
              if(a!=b):
                print(a)
                b=a
                i+=1
            if i==1:
               break;
        
parse_reddit()

def parse_reddit1(s):
    b=''
    soup=make_soup(s)
    #match=re.compile('title may-blank loggedin')
    match1=re.compile('\.(jpeg|jpg|png)')
    #for link in soup.find_all('a', {'class':['title may-blank loggedin']}):
    for link in soup.find_all('a', {'class': ['title', 'may-blank', 'loggedin']}):
        #soup.find_all('a',class_='title may-blank loggedin'):
      if re.search(match1,link['href']):
        a=link['href']
        if(a!=b):
          print(a)
          b=a
        #else:
         #i=0
         #for link in soup.find_all('a',{'rel':['nofollow', 'next']}):
          #soup1=make_soup(link['href'])
          #for link in soup1.find_all('a', {'class': ['title', 'may-blank', 'loggedin']}):
            #if re.search(match1,link['href']):
             # a=link['href']
              #if(a!=b):
               # print(a)
                #b=a
                #i+=1
            #if i==3:
               #break;

def count_reddit_website():
  s1='https://www.reddit.com/r/spaceporn/'
  #parse_reddit1(s1)
  i=51
  while(i<=501):
    s2='https://www.reddit.com/r/spaceporn/?count='+str(i)
    parse_reddit1(s2)
    i=i+51
#count_reddit_website()
