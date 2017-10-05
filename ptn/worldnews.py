import re
from bs4 import BeautifulSoup
from bs4 import SoupStrainer
import os
import httplib2
c=0
def make_soup(s):
   match=re.compile('https://|http://|www.|.com|.in|.org|gov.in')
   if re.search(match,s):
     http = httplib2.Http()
     status, response = http.request(s)
     page = BeautifulSoup(response,parse_only=SoupStrainer('a'))
     return page
   else:
     return None
    
def is_a_valid_link(href):
   match1=re.compile('http://|https://')
   match2=re.compile('/r/worldnews/comments/')
   match3=re.compile('modpost')
   return re.search(match1,href) and re.search(match2,href) and not re.search(match3,href)
def parse(s):
    global c
    temp_set=set()
    soup=make_soup(s)
    match4=re.compile('comments')
    if(soup!=None):
        for link in soup.find_all('a',attrs={'class':['title',' may-blank', 'loggedin']}):
                  temp_set.add(link.string+'\n'+link['href']+'\n')
                  print('\nPROMPT '+str(c+1)+'\n'+link.string+'\n'+link['href']+'\n')
    #for elements in temp_set:
     #  f.write('\nPROMPT '+str(c+1)+'\n'+elements)
      # c=c+1     
def count_next_of_current(s,m):
    soup=make_soup(s)
    y='https://www.reddit.com/r/'+m+'/'+select_tab+'/?count='
    match=re.compile(y)
    for link in soup.find_all('a',{'rel':['next']}):
        href=link['href']
        return href
def read_reddit_images(change_file_number,m,x):
    global f
    global select_tab
    select_tab=x
    x=m+'_'+select_tab+str(change_file_number)+'.txt'
    f=open(x,'w')
    maximum_number_of_next_pages=5000
    s='https://www.reddit.com/r/'+m+'/'+select_tab
    soup=make_soup(s)
    parse(s)
    count=0
    print('for '+m+' current page number is'+'\n')
    while(count<maximum_number_of_next_pages):
        s=count_next_of_current(s,m)
        if(s!=None):
            parse(s)
            count=count+1
            print(count)
        else:
            break
    f.close()

def maincall(m,i):
   read_reddit_images(i,m,'gilded')
   read_reddit_images(i,m,'top')
   read_reddit_images(i,m,'new')
   read_reddit_images(i,m,'controversial')
def subs():
   while(True):
     try:
       s=make_soup('https://www.reddit.com/')
       break
     except:
       continue
   t=open('mytext.txt','r')
   i=t.read()
   temp=int(i)
   temp=temp+1
   t.close()
   t=open('mytext.txt','w')
   t.write(str(temp))
   t.close()
   b=['worldnews','news','askreddit','learnprogramming','compsci','learnpython']
   #b=['worldnews','lifehacks','AskHistorians','programming','politics','compsci','javahelp','learnprogramming','cpp_questions','physics','writingprompts','getmotivated','news','gadgets','InternetIsBeautiful','india','science','IAmA','askscience','jokes','explainlikeimfive','technology','showerthoughts','bestof','']
   #b=b+['movies','documentaries','dataisbeautiful','history','AskReddit','funny','todayilearned','pics','books','space','philosophy']
   #b=b+['','','','']
   for k in b:
        maincall(k,i)
subs()
