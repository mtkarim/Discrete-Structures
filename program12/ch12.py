import sys
import re
from node import *
value = open(sys.argv[1]) #opening a file

disp=[]

for wall in value:
    disp.append(re.split(",",re.sub(r"\n", "",wall )))

    arr=[]
    arg=disp[0]

loc = ""
for row in disp:
     loc = ""
     if row[-1] is'1':
            iterator = 0
            loc += '{'
            for nod in arg[:-1]:
                if row[iterator]is '1':
                   loc +=nod
                else:
                    loc +="-" + nod
                if iterator + 1 < len(arg[: -1]):
                    loc += "."
                iterator += 1
            loc  += '}'
            arr.append(loc)

currentroot = Node(arr[0])
root = currentroot
for lis in arr[1:]:
    currentroot.add_child(Node(lis))
    currentroot = currentroot.child
print(root.getstring())


