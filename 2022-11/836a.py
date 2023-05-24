# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

from collections import Counter

def foo(s):
    d = Counter(s)
    ans = ''
    for k, v in d.items():
        ans = k * v + ans + k * v
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        print(foo(s))