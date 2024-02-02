# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, x):
    if n % x:
        return [-1]
    ans = [i for i in range(1, n+1)]
    ans[0] = x
    ans[-1] = 1
    i = 2 * x
    while i <= n:
        if n % i == 0:
            ans[x-1] = i
            x = i
        i += x
    return ans    

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, x = [int(i) for i in input().split()]
        start = False
        for i in foo(n, x):
            if start:
                print(end=' ')
            start = True
            print(i, end='')
        print()