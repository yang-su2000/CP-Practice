# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n):
    if n % 2:
        return [1] * n
    return [n+1] * (n-1) + [1]

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        start = False
        for i in foo(n):
            if start:
                print(end=' ')
            start = True
            print(i, end='')
        print()