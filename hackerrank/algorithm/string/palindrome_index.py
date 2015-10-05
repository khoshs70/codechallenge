'''
https://www.hackerrank.com/challenges/palindrome-index
'''
#!/usr/bin/py
def isann(thestr):
    x = 0
    y = len(thestr) - 1    
    while (x<y):
        if (thestr[x] == thestr[y]):
            x = x + 1
            y = y - 1
            continue
        else:
            return False
    return True
    
def findidx(thestr):    
    x = 0
    y = len(thestr) - 1    
    while (x<y):
        if (thestr[x] == thestr[y]):
            x = x + 1
            y = y - 1
            continue
        else:
            #cretae two new string
            newstr1 = thestr[:x] + thestr[x+1:]
            #print newstr1
            if (isann(newstr1) == True):
                return x
            newstr2 = thestr[:y] + thestr[y+1:]
            #print newstr2
            if (isann(newstr2) == True):
                return y
            break
    return -1
 
if __name__ == '__main__':
    t = input()
    for x in range(int(t)):
        thestr = raw_input().strip()        
        print findidx(thestr)

        