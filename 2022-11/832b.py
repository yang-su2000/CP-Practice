# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n):
    ls = []
    for _ in range(n):
        ls.extend(['B','A','N'])
    ans = []
    l = 1
    r = len(ls) - 1
    while l < r:
        ans.append([l+1, r+1])
        ls[l], ls[r] = ls[r], ls[l]
        while ls[l] != 'A':
            l += 1
        while ls[r] != 'N':
            r -= 1
    return len(ans), ans
        
# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ans, ls = foo(n)
        print(ans)
        for a, b in ls:
            print(a, b)