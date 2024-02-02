# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict
from collections import Counter

# python sample.py < input

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        n = int(input())
        s = input()
        c = Counter(s)
        mval = max(c.values())
        ans = max(n % 2, mval - (n - mval))
        print(ans)
