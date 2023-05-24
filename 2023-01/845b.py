# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    ls = [0] * int(1e5+1)
    mod = int(1e9+7)
    ls[1] = 1
    for i in range(2, int(1e5+1)):
        ls[i] = (ls[i-1] * i) % mod
    for _ in range(t):
        n = int(input())
        ans = ls[n] * n * (n - 1) % mod
        print(ans)