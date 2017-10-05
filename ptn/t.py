# -*- coding: utf-8 -*-
import urllib.request
from bs4 import BeautifulSoup
def get_site_html(url):
    source=(urllib.request).urlopen(url).read()
    return source

def collect_incoming_data(self, data):
        self.data.append(data.decode('utf-8'))
def encode_fix(url):
        line =(urllib.request).urlopen(url).read()
        lineStr = str( line, encoding='utf8' )
        return lineStr
def  get_tree(source):
    tree=BeautifulSoup((urllib.request.urlopen(source)))
    #print(tree)
    #print(tree.findAll('p'))
    #print(len(tree.findAll('p')))
def bin_equiv(x):
    s=0
    p=1
    while(x!=0):
        a=x%2
        s=s+p*a
        x=x//2
        p=p*10
    return s
def oct_equiv(x):
    s=0
    p=1
    while(x!=0):
        a=x%8
        s=s+p*a
        x=x//8
        p=p*10
    return s
def hex_equiv(x):
    s=0
    p=1
    while(x!=0):
        a=x%16
        s=s+p*a
        x=x//16
        p=p*10
    return s
def   cusat_run():
    s='http://dspace.cusat.ac.in/jspui/handle/123456789/'
    for i in range(8770, 8827,1):
      x=s+str(i)+'1'
      source=urllib.request.urlopen(x)
      tree=BeautifulSoup(source)
      if('.pdf' in tree.findAll('href')):
           urllib.request.urlopen('href')
def c_r():
    import httplib2
    from bs4 import BeautifulSoup, SoupStrainer
    http = httplib2.Http()
    status, response = http.request('http://www.nytimes.com')
    for link in BeautifulSoup(response, parse_only=SoupStrainer('a')):
      if link.has_attr('href')& '.pdf' in 'href':
         print (link['href'])
#c_r()
def play_r():
    s='http://dspace.cusat.ac.in/jspui/handle/123456789/'
    for i in range(8770, 8827,1):
      x=s+str(i)+'1'
      import httplib2
      from bs4 import BeautifulSoup, SoupStrainer
      http = httplib2.Http()
      status, response = http.request(x)
      if link.has_attr('href'):
         print (link['href'])
def play_rr():
    import httplib2
    import re
    from bs4 import BeautifulSoup
    # find ".html" or ".pdf" in a string
    match = re.compile('\.(pdf)')
    # parse page content
    s='http://dspace.cusat.ac.in/jspui/handle/123456789/'
    for i in range(8770, 8872,1):
      x=s+str(i)+'1'
      http = httplib2.Http()
      status, response = http.request(x)
      page = BeautifulSoup(response)
      # check links
      for link in page.findAll('a'):
         try:
           href = link['href']
           if re.search(match, href):
              print (href)
         except KeyError:
            pass
play_rr()
#if __name__=="__main__":
    #print("png" in encode_fix('http://google.com'))
    #print('Python' in encode_fix('http://pyladies.com'))
    #x=encode_fix('http://python.org')
    #for i in range(0,10,1):
     #   print(x[i])
    #print(bin_equiv(int(input('enter a number to convert to binary\n'))))
    #print(oct_equiv(int(input('enter a number to convert to oct\n'))))
    #print(hex_equiv(int(input('enter a number to convert to hex\n'))))
    #get_tree('http://python.org')
    #cusat_run()
