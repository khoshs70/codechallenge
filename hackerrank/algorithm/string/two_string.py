'''
https://www.hackerrank.com/challenges/two-strings
'''

#!/usr/bin/py
def findsubstr(a,b):    
    seta = set(a)
    setb = set(b)
    inset = seta&setb    
    if not inset:
        return "NO"
    else:
        return "YES"
    
if __name__ == '__main__':
    t = input()
    for x in range(int(t)):        
        a = ["%c" % item  for item in raw_input().strip()]
        b = ["%c" % item  for item in raw_input().strip()]        
        print findsubstr(a,b)
