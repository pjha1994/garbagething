from bs4 import BeautifulSoup
import urllib
import httplib2
import re
http = httplib2.Http()
s='http://hotfoxybabes.com/'
status, response = http.request(s)
page = BeautifulSoup(response)
match=re.compile('.jpg|.jpeg|.png')
for link in page.findAll('a'):
    if 'img' in link['href']:
       print(link['href'])
         
