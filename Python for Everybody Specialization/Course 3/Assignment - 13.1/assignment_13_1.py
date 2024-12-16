from urllib.request import urlopen
from bs4 import BeautifulSoup
import ssl
import re

total = 0

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

#url = input('Enter - ')
html = urlopen("http://py4e-data.dr-chuck.net/comments_1734147.html", context=ctx).read()
soup = BeautifulSoup(html, "html.parser")

# Retrieve all of the anchor tags
tags = soup('span')
for tag in tags:
    total = total + int(tag.contents[0])
print(total)


    
