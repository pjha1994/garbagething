import praw
from praw import Reddit
def check5():
    r = Reddit(user_agent='Some description')
    thread = r.get_submission(submission_id='3eret9')
    comments = praw.helpers.flatten_tree(thread.comments)
    for comment in comments:
        body = getattr(comment,'body','')  # not all comments have 'body'
        print(body).encode('ascii','ignore')
check5()
