# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict
# from sortedcollections import SortedList, SortedSet, SortedDict

def foo(n):
    return (n - 6) // 3

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(foo(n))