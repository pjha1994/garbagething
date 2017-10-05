#For other tasks on reddit:
                         #Modify the file name f and the 'for' loop in parse()
                         #Modify match in count_next_of current()
                         #Modify i and s in read_reddit_images()
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
     page = BeautifulSoup(response)
     return page
   else:
     return None
def is_a_valid_link(href):
   match1=re.compile('http://|https://')
   match2=re.compile('/user/|/comments/|.webm|.gfy')
   return re.search(match1,href) and not re.search(match2,href)
def parse(s):
    b=''
    c=0
    soup=make_soup(s)
    match=re.compile('\.(jpg|jpeg|png)')
    if(soup!=None):
        for link in soup.find_all('a',class_=['title', 'may-blank', 'loggedin']):
            href=link['href']
            a=href
            if is_a_valid_link(href):
                if re.search(match,href) and a!=b:
                    print(a)
                    b=a
                elif a!=b:
                     parse_another_level(a)
                     b=a
                     c=c+1
def parse_another_level(s):
    b=''
    flag=0
    soup=make_soup(s)
    match=re.compile('\.(jpg|jpeg|png)')
    match1=re.compile('http://|https://|www.')
    if(soup!=None):
        for link in soup.find_all('a',attrs={'href':True}):
          a=link['href']
          if re.search(match,a) and a!=b:
              if not re.search(match1,a):
                 a='https:'+a
              print(a)
              flag=1
              b=a
    if (flag==0):
        f.write(s)
        f.write('\n')
def count_next_of_current(s):
    soup=make_soup(s)
    match=re.compile('https://www.reddit.com/r/AmateurEarthPorn/?count=')
    for link in soup.find_all('a',{'rel':['next']}):
        href=link['href']
        return href
def read_reddit_images():
    global f
    f=open('AmateurEarthPorn.txt','w')
    i=int(input('Enter the number of NEXT pages from the front AmateurEarthPorn page that you want to scrape\n'))
    s='https://www.reddit.com/r/AmateurEarthPorn/'
    #soup=make_soup(s)
    parse(s)
    count=0
    while(count<i):
        s=count_next_of_current(s)
        if(s!=None):
            parse(s)
            count=count+1
        else:
            break
    f.close()
read_reddit_images()
