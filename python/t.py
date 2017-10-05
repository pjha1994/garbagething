import requests
from bs4 import BeautifulSoup
def a():
   r = requests.get('https://www.reddit.com/')
   #print(r.text)
   soup=BeautifulSoup(r.text,'html5lib')
   print(soup)
a()
