#-*- coding:utf-8 -*-
# Python 3.8
# need Libraries: beautifulsoup4, requests

"""
This python file is for getting problem number and making .cpp files automatically in one page
This Programs Returns
─ FolderName
├─ 1234.cpp
├─ 2345.cpp
├─ 75441.cpp
├─ ...
"""

import sys
import requests
import os
from bs4 import BeautifulSoup

if(len(sys.argv) != 3):
    print("Input is not correct\n")
    print("Proper USE")
    print("===========================")
    print("./" + sys.argv[0], "BaekJoonPageURL", "FolderName")
    print("===========================")
    sys.exit()

baseURL = "https://www.acmicpc.net"
webpage = requests.get(sys.argv[1])
folder_name = sys.argv[2]
newFolder = "./" + folder_name
if os.path.exists(newFolder) != True:
    os.mkdir(newFolder)

soup = BeautifulSoup(webpage.content, "html.parser")

problem_number = soup.find_all(attrs={'class':'list_problem_id'})
# problem_url = soup.tr.
problemset = soup.find(id="problemset")
tr = problemset.findChildren("tr", recursive=True)
list_problem_id = soup.find_all(attrs={'class':'list_problem_id'})

for each in list_problem_id:
    link = each.parent.find('a')['href']
    newFilePath = newFolder + "/" + each.get_text() + ".cpp"
    if os.path.exists(newFilePath):
        continue
    else:
        with open(newFilePath, "w") as f:
            f.write("// " + baseURL + link)