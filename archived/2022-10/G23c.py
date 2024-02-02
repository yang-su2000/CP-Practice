# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, ls):
    s = [] # (remain, idx)
    for i in range(1, n):
        if ls[i] < ls[i-1]:
            s.append((ls[i-1] - ls[i], i))
    s.sort()
    # print(s)
    ans = []
    i = 0
    while i < len(s) and len(ans) < n:
        remain, idx = s[i]
        ans.append(idx+1)
        remain -= len(ans)
        if remain <= 0:
            i += 1
    while len(ans) < n:
        ans.append(1)
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        for i in foo(n, ls):
            print(i, end=' ')
        print()