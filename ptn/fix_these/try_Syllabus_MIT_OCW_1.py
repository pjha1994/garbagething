import re
from bs4 import BeautifulSoup,SoupStrainer 
import os
import httplib2
def make_soup(s):
    http=httplib2.Http()
    status,response=http.request(s)
    page=BeautifulSoup(response)
    return page
def parse(s):
    flag=1
    lum1=''
    lum2=''
    soup1=make_soup(s)
    match=re.compile('download-course-materials')
    match1=re.compile('Syllabus')
    if 'download-course-materials' in soup1:
     for link in soup1.findAll('a'):
        href=link['href']
        if re.search(match,href):
            lum='http://ocw.mit.edu'+href
            match2=re.compile('.zip')
            soup2=make_soup(lum)
            for link in soup2.findAll('a'):
                href1=link['href']
                if re.search(match2,href1):
                    lum2='http://ocw.mit.edu'+href1
                    return lum2
    else:
        for link in soup1.findAll('a'):
           href=link['href']
           if re.search(match1,href):
               lum='http://ocw.mit.edu'+href
               print(lum)                
    return ''
def course_pages_on_mit_ocw():
    f=open('mit1.txt','w')
    s='http://ocw.mit.edu/courses/brain-and-cognitive-sciences/'
    soup1=make_soup(s)
    b=''
    match=re.compile('/courses/brain-and-cognitive-sciences/')
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
