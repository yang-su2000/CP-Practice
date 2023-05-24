# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(a, b):
    d = {'S': 1, 'M': 2, 'L': 3}
    a1 = a[-1]
    b1 = b[-1]
    if d[a1] == 1:
        if d[b1] == 1:
            if len(a) == len(b):
                return '='
            elif len(a) < len(b):
                return '>'
            else:
                return '<'
        else:
            return '<'
    elif d[a1] == 2:
        if d[b1] == 2:
            return '='
        elif d[b1] == 1:
            return '>'
        else:
            return '<'
    else:
        if d[b1] == 3:
            if len(a) == len(b):
                return '='
            elif len(a) < len(b):
                return '<'
            else:
                return '>'
        else:
            return '>'

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        a, b = input().split()
        print(foo(a, b))