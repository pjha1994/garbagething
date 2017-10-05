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
    b=''
    soup1=make_soup(s)
    match=re.compile('download-course-materials')
    match1=re.compile('http://|https://|www.')
    match3=re.compile('/courses/mathematics/')
    for link in soup1.find_all('a'):
        href=link['href']
        if re.search(match,href) and re.search(match3,href):
            lum='http://ocw.mit.edu'+href
            flag=1
            match4=re.compile('.zip')
            soup2=make_soup(lum)
            for link in soup2.find_all('a'):
                href1=link['href']
                if re.search(match4,href1) and href1!=b:
                    lum2='http://ocw.mit.edu'+href1
                    #print(lum2)
                    b=href1
    if(flag==0 and find_syllabus_otherwise(s)!=None):
        print(find_syllabus_otherwise(s))
        #f.write(find_syllabus_otherwise(s))
        #f.write(s)
        f.write('\n')
def find_syllabus_otherwise(s):
    soup=make_soup(s)
    match=re.compile('Syllabus')
    for link in soup.findAll('a'):
        href=link['href']
        if re.search(match,href):
            lum='http://ocw.mit.edu'+href
            return lum
def course_pages_on_mit_ocw():
    global f
    f=open('mit.txt','w')
    s='http://ocw.mit.edu/courses/mathematics/'
    soup1=make_soup(s)
    b=''
    match=re.compile('/courses/mathematics/')
    for link in soup1.find_all('a',class_='preview',attrs={'rel':'coursePreview'}):
        href=link['href']
        if re.search(match,href):
            a='http://ocw.mit.edu'+href
            if(a!=b):
                parse(a)
                b=a
    f.close()
course_pages_on_mit_ocw()
