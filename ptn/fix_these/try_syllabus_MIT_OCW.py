import re
from bs4 import BeautifulSoup
import os
import httplib2
def make_soup(s):
    http=httplib2.Http()
    status,response=http.request(s)
    page=BeautifulSoup(response)
    return page
def parse(s):
    flag=0
    lum1=''
    lum2=''
    soup1=make_soup(s)
    match=re.compile('download-course-materials')
    for link in soup1.findAll('a'):
        href=link['href']
        if ((not re.search(match,href)) and(re.search('Syllabus',href)) and flag!=1):
            print('http://ocw.mit.edu'+link['href'])
            flag=0
        elif re.search(match,href):
            flag=1
            return('http://ocw.mit.edu'+link['href'])
    return ''
def course_pages_on_mit_ocw():
    f=open('mit.txt','w')
    s='http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/'
    soup1=make_soup(s)
    b=''
    match=re.compile('/courses/electrical-engineering-and-computer-science/')
    for link in soup1.findAll('a'):
        href=link['href']
        if re.search(match,href):
            a='http://ocw.mit.edu'+href
            if(a!=b):
                x=parse(a)
                b=a
                if(x!=''):
                    f.write(x)
                    f.write('\n')
    f.close()
course_pages_on_mit_ocw()
