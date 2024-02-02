# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, ls):
    presum = [0] * n
    presum[0] = ls[0]
    for i in range(1, n):
        presum[i] = presum[i-1] + ls[i]
    ans = n
    for i in range(1, n):
        thick = i
        sum = presum[i-1]
        pre_j = i-1
        thick2 = 0
        j = i
        while j < n:
            thick2 += 1
            if presum[j] - presum[pre_j] == sum:
                thick = max(thick, thick2)
                pre_j = j
                thick2 = 0
            j += 1
        if pre_j == n-1:
            ans = min(ans, thick)
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))