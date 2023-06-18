# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input

if __name__ == '__main__':
    n = int(input())
    ans1 = n // 5 * 5
    ans2 = n // 5 * 5 + 5
    ans = None
    d = 101
    if 0 <= ans1 <= 100 and n - ans1 < d:
        ans = ans1
        d = n - ans1
    if 0 <= ans2 <= 100 and ans2 - n < d:
        ans = ans2
        d = n - ans2
    print(ans)