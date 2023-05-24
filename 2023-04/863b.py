# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, x1, y1, x2, y2 = [int(i) for i in input().split()]
        x1 -= 1
        y1 -= 1
        x2 -= 1
        y2 -= 1
        n2 = n // 2
        if x1 >= n2:
            x1 = n - x1 - 1
        if y1 >= n2:
            y1 = n - y1 - 1
        if x2 >= n2:
            x2 = n - x2 - 1
        if y2 >= n2:
            y2 = n - y2 - 1
        l1 = min(x1, y1)
        l2 = min(x2, y2)
        print(abs(l1 - l2))