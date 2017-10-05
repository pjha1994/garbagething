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
    b=''
    soup=make_soup(s)
    match=re.compile('\.(jpg|jpeg|png)')
    for link in soup.find_all('a',{'class':['fileThumb', 'image-expanded-anti']}):
    #for link in soup.findAll('a'):
        href=link['href']
        if re.search(match,href):
            a=href
            if(a!=b):
                print('http:'+a)
                #f.write(a)
                #f.write('\n')
                b=a
def c4han_s():
    s='http://boards.4chan.org/s/'
    parse(s)
c4han_s()

def c4han_span_s():
    s='http://boards.4chan.org/s/'
    soup=make_soup(s)
    for lin in soup.find_all('span',{'class':['summary','desktop']}):
        parse(span)
#c4han_span_s()
