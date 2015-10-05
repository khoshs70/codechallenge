'''
https://www.hackerrank.com/challenges/lonely-integer
There are N integers in an array A. All but one integer occur in pairs. Your task is to find the number that occurs only once.
'''

#!/usr/bin/py
def lonelyinteger(lst):    
    dct = {}
    for key in lst:
        #if key in dct:
        if dct.has_key(key):
            dct.pop(key)
        else:
            dct[key] = 1
    answer = dct.keys()[0]
    return answer
    
if __name__ == '__main__':
    a = input()
    b = map(int, raw_input().strip().split(" "))    
    print lonelyinteger(b)
