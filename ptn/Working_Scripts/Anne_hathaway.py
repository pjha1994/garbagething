#For other tasks on reddit:
                         #Modify the file name f and the 'for' loop in parse()
                         #Modify match in count_next_of current()
                         #Modify i and s in read_reddit_images()

import re
from bs4 import BeautifulSoup
import os
import httplib2
def make_soup(s):
    http = httplib2.Http()
    status, response = http.request(s)
    page = BeautifulSoup(response)
    return page
def parse(s):
    global b
    b=''
    soup=make_soup(s)
    match=re.compile('\.(jpg|jpeg|png)')
    for link in soup.find_all('a',{'class':['title', 'may-blank', 'loggedin']}):
        href=link['href']
        if re.search(match,href):
            a=href
            if(a!=b):
                print(a)
                f.write(a)
                f.write('\n')
                b=a
def count_next_of_current(s):
    soup=make_soup(s)
    match=re.compile('https://www.reddit.com/r/AnneHathaway/?ref=search_subreddits&count=')
    for link in soup.find_all('a',{'rel':['next']}):
        href=link['href']
        return href
def read_reddit_images():
    global f
    f=open('annehathaway.txt','w')
    i=int(input('Enter the number of NEXT pages from the front Anne hathaway page that you want to scrape\n'))
    s='https://www.reddit.com/r/AnneHathaway/'
    soup=make_soup(s)
    parse(s)
    global count
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
