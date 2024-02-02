# import math, heapq, bisect, itertools, functools
from collections import Counter

# python sample.py < input

if __name__ == '__main__':
    h, w = [int(i) for i in input().split()]
    d = {}
    counter = {}
    for row in range(h):
        s = input()
        start = -1
        end = -1
        for j, c in enumerate(s):
            if c == '#':
                if start == -1:
                    start = j
            elif c == '.' and start != -1:
                end = j - 1
                break
        if start != -1:
            if end == -1:
                end = w - 1
            if (start, end) not in d:
                d[(start, end)] = row
                counter[(start, end)] = 1
            else:
                counter[(start, end)] += 1
    # print(d, counter)
    maxd = max(b-a for a, b in counter.keys())
    major = None
    minor = None
    r, c = None, None
    for val, count in counter.items():
        if val[1] - val[0] < maxd:
            minor = val
        else:
            major = val
    # print(minor, major)
    if minor[0] != major[0]:
        r = d[minor]
        c = minor[0] - 1
    else:
        r = d[minor]
        c = minor[1] + 1
    print(r+1, c+1)
        