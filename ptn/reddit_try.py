import re
from bs4 import BeautifulSoup
import os
import httplib2
def make_soup(s):
  http = httplib2.Http()
  status, response = http.request(s)
  page = BeautifulSoup(response)
  return page
def parse_reddit():
    s='https://www.reddit.com/r/worldnews/'
    soup=make_soup(s)
    match=re.compile(('jpe|jpeg|png'))
    for link in soup.findAll('a'):
      if re.search(match,'href'):
        print(link['href'])
parse_reddit()
