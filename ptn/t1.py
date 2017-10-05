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
    tree=BeautifulSoup(source)
    return tree
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
if __name__=="__main__":
    #print("png" in encode_fix('http://google.com'))
    #print('Python' in encode_fix('http://pyladies.com'))
    #x=encode_fix('http://python.org')
    #for i in range(0,10,1):
     #   print(x[i])
    #print(bin_equiv(int(input('enter a number to convert to binary\n'))))
    #print(oct_equiv(int(input('enter a number to convert to oct\n'))))
    #print(hex_equiv(int(input('enter a number to convert to hex\n'))))
    print(get_tree(encode_fix('http://google.com')))
