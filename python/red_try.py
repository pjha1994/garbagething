from praw import Reddit
import praw
#!/usr/bin/env python
# -*- coding: utf-8 -*-
def check1():
    
    r = Reddit(user_agent='Some description')
    submission = r.get_submission(submission_id='3eret9')
    #print(dir(submission.comments.body))
    #print(submission.selftext)
    f.write(submission.selftext)
    #print(submission.comments._extract_more_comments)
    x=len(submission.comments)
    print(x)
    comm=submission.replace_more_comments(limit=1, threshold=0)
    print(dir(comm))
    #for comment in comm:
        #print(comm.replies)
    #for comment in submission.replace_more_comments:
     #      print(comment.body+'\n')
           #f.write(comment.body+'\n')
           #print(comment.replies)
        #for c in comment.replies:
           #f.write(c)
           #print(comment.body.replies)
def check2():
    r = Reddit(user_agent='Some description')
    subreddit=r.get_subreddit('worldnews')
    i=0
    for submission in subreddit.get_new(limit=999):
        print (str(i)+'  '+submission.title)
        #f.write((str(str(i)+'  '+submission.title)).encode('utf-8'))
        i=i+1
def check3():
    r = Reddit(user_agent='Some description')
    subreddit=r.get_subreddit('worldnews')
    i=0
    for submission in subreddit.get_hot(limit=999):
        print (str(i)+'  '+submission.title)
        #f.write((str(i)+'  '+submission.title).encode('utf-8'))
        i=i+1
def check4():
    r = Reddit(user_agent='Some description')
    subreddit=r.get_subreddit('worldnews')
    i=0
    for submission in subreddit.get_top(limit=999):
        print (str(i)+'  '+submission.title)
        #f.write((str(i)+'  '+submission.title).encode('utf-8'))
        i=i+1
def check5():
    r = Reddit(user_agent='Some description')
    thread = r.get_submission(submission_id='3eret9')
    comments = praw.helpers.flatten_tree(thread.comments)
    i=0
    for comment in comments:
        body = getattr(comment,'body','')  # not all comments have 'body'
        print(body).encode('ascii','ignore')
        x=body.encode('ascii','ignore')
        f.write(str(i)+"\n\n\n"+x)
        i+=1
def m():
    global f
    f=open('worldnews.txt','w')
    #check1()
    #check2()
    #check3()
    #check4()
    check5()
    f.close()
m()
