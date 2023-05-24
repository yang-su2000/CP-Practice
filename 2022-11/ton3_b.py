# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, s):
    ans = len([i for i in s if i == '0']) * len([i for i in s if i == '1'])
    count = 0
    char = '/'
    for i in s:
        if i == char:
            count += 1
        else:
            ans = max(ans, count**2)
            char = i
            count = 1
    ans = max(ans, count**2)
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        print(foo(n, s))