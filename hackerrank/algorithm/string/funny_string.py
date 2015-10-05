def check(txt):
    #print "checking",txt
    x = 0
    y = len(txt)-1
    while (x<y):
        if (abs(ord(txt[x])-ord(txt[x+1]))!=abs(ord(txt[y])-ord(txt[y-1]))):            
            return False
        else:
            x=x+1
            y=y-1
    return True

num = raw_input()
result=[]
for x in range(int(num)):
    txt = raw_input()
    if (check(txt)==True):
        result.append("Funny")
    else:
        result.append("Not Funny")
for item in result:
    print item

'''
# Enter your code here. Read input from STDIN. Print output to STDOUT

import fileinput

line = fileinput.input()
n = int(line[0])
for i in range(n):
    s = line[i+1].strip()
    lst = [ord(c) for c in s]
    nlst = lst[:]
    nlst.reverse()
    
    ln = len(s)
    funny = True
    for k in range(1, ln):
        if abs(lst[k]-lst[k-1]) != abs(nlst[k]-nlst[k-1]):
            funny = False
            break
            
    if funny: print "Funny"
    else: print "Not Funny"    
'''