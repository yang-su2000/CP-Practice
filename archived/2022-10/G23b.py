# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, ls):
    cur = ls[0]
    count = 1
    s = [] # [val, count]
    for i in range(1, n):
        if ls[i] == cur:
            count += 1
        else:
            s.append([cur, count])
            cur = ls[i]
            count = 1
    s.append([cur, count])
    print(s)
    d0 = [0] * len(s)
    d1 = [0] * len(s)
    d0[0] = 0 if s[0][0] == 0 else s[0][1]
    d1[0] = 0 if s[0][0] == 1 else s[0][1]
    for i in range(1, len(s)):
        if s[i][0] == 0:
            d0[i] = d0[i-1]
            d1[i] = min(d1[i-1] + s[i][1], max(d1[i-1], s[i][1]))
        else:
            d0[i] = d0[i-1] + s[i][1]
            d1[i] = min(d0[i-1], d1[i-1])
    print(d0, d1)
    return min(d0[-1], d1[-1])
    # dp = [[None] * n for _ in range(2)]
    # d1 = [None] * n
    # dp[0][0] = 0 if ls[0] == 0 else 1
    # dp[1][0] = 0 if ls[0] == 1 else 0
    # d1[0] = 0 if ls[0] == 0 else 1
    # for i in range(1, n):
    #     if ls[i] == 0:
    #         dp[0][i] = min(dp[0][i-1], dp[1][i-1] + d1[i-1])
    #         if d1[i-1]:
    #             dp[1][i] = dp[1][i-1] + 1
    #             d1[i] = d1[i-1]
    #         else:
    #             dp[1][i] = dp[1][i-1] + 1
    #             d1[i] = d1[i-1]
    #     elif ls[i] == 1:
    #         dp[0][i] = min(dp[0][i-1] + 1, dp[1][i-1] + d1[i-1] + 1)
    #         dp[1][i] = dp[1][i-1]
    #         d1[i] = d1[i-1] + 1
    #         if dp[0][i-1] <= dp[1][i]:
    #             dp[1][i] = dp[0][i-1]
    #             d1[i] = 1
    # print(dp)
    # print(d1)
    # return min(dp[0][-1], dp[1][-1])

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))