import re
from bs4 import BeautifulSoup
import os
import httplib2
from time import sleep
def make_soup(s):
    http=httplib2.Http()
    status,response=http.request(s)
    sleep(10)
    page=BeautifulSoup(response)
    return page
def parse(s,domain):
    flag=1
    lum1=''
    lum2=''
    soup1=make_soup(s)
    match=re.compile('.pdf')
    for link in soup1.findAll('a'):
        href=link['href']
        if re.search(match,href):
            lum=domain+href
            #print(lum)
            return lum
    return ''
def course_pages_on_mit_ocw():
    f=open('nptel.txt','w')
    s='http://nptel.ac.in/courses.php?disciplineId=106'
    soup1=make_soup(s)
    b=''
    match=re.compile('downloads/')
    match1=re.compile('http://textofvideo.nptel.iitm.ac.in/video.php?')
    for link in soup1.findAll('a'):
        href=link['href']
        print(href)#testing
        if re.search(match,href):
            a='http://nptel.ac.in/'+href
            #print(a)#testing
            if(a!=b):
                x=parse(a,'http://nptel.ac.in')
                print(x)
                b=a
                if(x!=''):
                    f.write(x)
                    f.write('\n')
        elif re.search(match1,href):
            a=href
            #print(a)#testing
            if(a!=b):
                x=parse(a,'http://textofvideo.nptel.iitm.ac.in/')
                #print(x)#testing
                b=a
                if(x!=''):
                    f.write(x)
                    f.write('\n')
    f.close()
course_pages_on_mit_ocw()

def test():
    soup=make_soup('http://nptel.ac.in/courses.php?disciplineId=106')
    for link in soup.findAll('a'):
        href=link['href']
        print(href)
#test()

def parse2():
    for i in range(2011,2100,1):
        x='http://nptel.ac.in/downloads/10610'+str(i)+'/'
        soup=make_soup(x)
        match=re.compile('.pdf')
        for link in soup.findAll('a'):
            href=link['href']
            if re.search(match,href):
                print(i,' http://nptel.ac.in'+href)
parse2()
