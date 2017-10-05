import requests
def count_next_of_current(s):
    soup=make_soup(s)
    match=re.compile('https://www.reddit.com/r/gonewildcurvy/?count=')
    for link in soup.find_all('a',{'rel':['next']}):
        href=link['href']
        return href
def work(s):
    subreddit = 'nsfw'
    user_agent = 'Reddit JSON API teaching example/1.0'
    num_posts = 10000
    s=s+'.json?limit={}'
    #posts = requests.get('https://www.reddit.com/r/{}/.json?limit={}'.format(subreddit, num_posts),
    posts = requests.get(s.format(num_posts),
                headers={'User-Agent': user_agent}).json()

    for post in posts['data']['children']:
         print('{post[url]:40} {post[title]}'.format(post=post['data']))
def run():
   s='https://www.reddit.com/r/gonewildcurvy/'
   work(s)
   i=0
   while(i<4):
      s=count_next_of_current(s)
      work(s)
      i=i+1
run()


