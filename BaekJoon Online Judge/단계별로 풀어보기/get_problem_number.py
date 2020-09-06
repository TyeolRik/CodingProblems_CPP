#-*- coding:utf-8 -*-

# This python file is for getting problem number and making .cpp files automatically in one page

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

webpage = requests.get(sys.argv[1])
folder_name = sys.argv[2]
# os.mkdir("./" + folder_name)

soup = BeautifulSoup(webpage.content, "html.parser")

problem_number = soup.find_all(attrs={'class':'list_problem_id'})
# problem_url = soup.tr.
print(soup.find_all(attrs={'tr':''})[0])

"""
for each in problem_number:
    with open(each + ".cpp", "w") as f:
        f.write("//")
    print(each.string)
"""