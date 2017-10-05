import urllib3
#from BeautifulSoup import BeautifulSoup
# or if you're using BeautifulSoup4:
#from pyquery import *
from bs4 import BeautifulSoup
def a():
 soup = BeautifulSoup(urllib3.PoolManager().request('GET','http://google.com'))

 for row in soup('table', {'class': 'spad'})[0].tbody('tr'):
    tds = row('td')
    print (tds[0].string, tds[1].string)
    # will print date and sunrise
a()
