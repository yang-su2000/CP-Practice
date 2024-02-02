# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, a, q, ls):
    ans = [0] * n
    ans[0] = 1
    for i in range(1, n):
        ans[i] = min(ans[i-1] + 1, i + 1, a[i])
    sums = [0] * n
    sums[0] = 1
    for i in range(1, n):
        sums[i] = sums[i-1] + ans[i]
    for i in range(q):
        p, x = ls[i]
        prev = a[p-1]
        if prev == x:
            print(sums[-1])
            continue
        a[p-1] = x
        sums_i = 0
        ans_i = 0
        if p-1 > 0:
            sums_i = sums[p-2]
            ans_i = ans[p-2]
        for j in range(p-1, n):
            ans_i = min(ans_i + 1, j + 1, a[j])
            sums_i += ans_i
            if ans_i == ans[j]:
                sums_i += sums[-1] - sums[j]
                break
        a[p-1] = prev
        print(sums_i)

# python sample.py < input.txt

if __name__ == '__main__':
    n = int(input())
    a = [int(i) for i in input().split()]
    q = int(input())
    ls = []
    for _ in range(q):
        ls.append([int(i) for i in input().split()])
    foo(n, a, q, ls)