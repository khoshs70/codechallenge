'''
https://www.hackerrank.com/challenges/simple-array-sum
'''
sum = 0 
def acum(x):
    global sum
    sum += int(x)
if __name__ == '__main__':
    n = input()
   
    lst = map(acum, raw_input().strip().split())
    print sum
    