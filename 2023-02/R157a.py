# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    n, a, b, c, d = [int(i) for i in input().split()]
    if abs(b - c) > 1:
        print('No')
        exit(0)
    if b == 0 and c == 0:
        if a and d:
            print('No')
            exit(0)
    print('Yes')