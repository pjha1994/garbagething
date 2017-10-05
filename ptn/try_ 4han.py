#PROXY IN LIBRARY ELSE BLOCKED

import re
import requests
from bs4 import BeautifulSoup
from pprint import pprint
import os
import httplib2
import json
def make_soup(s):
   match=re.compile('https://|http://|www.|.com|.in|.org|gov.in')
   if re.search(match,s):
     http = httplib2.Http()
     status, response = http.request(s)
     #print(status, response)
     page = BeautifulSoup(response)
     return page
   else:
     return None
def is_a_valid_link(href):
   match1=re.compile('http://|https://')
   match2=re.compile('//i.4cdn.org/')
   return re.search(match1,href) and re.search(match2,href)
def read_link():
    #s='http://boards.4chan.org/s/catalog'
    #soup=make_soup(s)
    #for links in soup.find_all('a'):
     #   print(links)
     #results=requests.get('https://a.4cdn.org/wg/catalog.json').json()
     results=requests.get('http://boards.4chan.org/wg/catalog.json').json()
     f=open('AmateurEarthPorn.txt','w')
     f.write(str(results))
     #for a in results:
      #  print(a)
     for index, item in enumerate(results):
        #print (index, item)
        f.write(str(index))
        f.write(str(item))
        break
     x=len(results)
     #print(results.count('filename'))
     #print("https://boards.4chan.org/{}/thread/{}".format('wg',thread['no']))
     #pprint(results[0]['threads'][2]['filename'])
     #print(https://boards.4chan.org/%7B%7D/thread/%7B%7D%22.format('wg',thread['no']))
read_link()
