# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input

if __name__ == '__main__':
    d = {'A': 0, 'B': 3, 'C': 4, 'D': 8, 'E': 9, 'F': 14, 'G': 23}
    p, q = [i for i in input().split()]
    print(abs(d[p] - d[q]))