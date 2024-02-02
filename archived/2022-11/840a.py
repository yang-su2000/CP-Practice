# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

from collections import defaultdict

def foo(n, ls):
    d = defaultdict(int)
    for val in ls:
        for i, c in enumerate(str(bin(val))[2:][::-1]):
            if c == '1':
                d[i] += 1
            else:
                d[i] = d[i]
    # print(d.items())
    _max = ''
    _min = ''
    for p, count in sorted(d.items(), reverse=True):
        if count >= 1:
            _max += '1'
        else:
            _max += '0'
        if count == n:
            _min += '1'
        else:
            _min += '0'
    if _max == '':
        _max = 0
    else:
        _max = int(_max, 2)
    if _min == '':
        _min = 0
    else:
        _min = int(_min, 2)
    # print(_max, _min)
    return _max - _min

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))