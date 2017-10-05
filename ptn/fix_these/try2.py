import httplib2
from bs4 import  BeautifulSoup
def make_soup(s):
    http=httplib2.Http()
    status,response=http.request(s)
    page=BeautifulSoup(response)
    return page
print(make_soup('http://ocw.mit.edu/courses/brain-and-cognitive-sciences/9-00sc-introduction-to-psychology-fall-2011/'))
