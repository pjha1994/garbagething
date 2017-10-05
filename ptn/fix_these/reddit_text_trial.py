import re
from bs4 import BeautifulSoup
import os
import httplib2
def make_soup(s):
  http = httplib2.Http()
  status, response = http.request(s)
  page = BeautifulSoup(response)
  return page
def parse():
    s='https://www.reddit.com/r/worldnews/comments/3du2sk/uk_wants_10_year_prison_sentence_for_online/'
    soup=make_soup(s)
    div = soup.find('div', {'class': ['usertext-body may-blank-within md-container ']})
    children = div.find('div',{'class':['md']})
    print(children)
    #children=div.find_all('p')
    #subchild=children.findChildren('div',{'classs':['md']})
    #print(subchild)
#    for p in subchild:
#      print (p.get_text())
      
parse()
