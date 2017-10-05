from bs4 import BeautifulSoup
import mechanize

url = "http://web2.nyrrc.org/cgi-bin/start.cgi/mar-programs/archive/archive_search.html"

browser = mechanize.Browser()
browser.addheaders = [
    ('user-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.2.3) Gecko/20100423 Ubuntu/10.04 (lucid) Firefox/3.6.3'),
    ('accept', 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8')
]
browser.set_handle_robots(False)

# get years
browser.open(url)
browser.form = list(browser.forms())[0]
select = browser.form.controls[3]
years = [item.name for item in select.get_items()]

# process year by year
for year in years:
    print ("Processing year=" + year)

    # open up search form again, fill out an appropriate year and submit
    browser.open(url)
    time.sleep()
    browser.form = list(browser.forms())[0]
    select = browser.form.controls[3]

    browser.form['input.searchyear'] = [year]
    browser.form['search.method'] = ['search.flat']
    browser.submit()

    # get overall winners
    soup = BeautifulSoup(browser.response())
    print (soup.find(text='Overall Winners').parent.parent.parent.find_next_sibling('tr').find('pre').text)
