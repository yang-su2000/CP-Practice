# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    n, m = [int(i) for i in input().split()]
    ls = []
    for _ in range(m):
        ls.append([int(i)-1 for i in input().split()])
    A = [[False] * n for _ in range(n)]
    # print(ls)
    for i in range(m):
        for j in range(n-1):
            a, b = ls[i][j], ls[i][j+1]
            A[a][b] = True
            A[b][a] = True
    # print(A)
    ans = 0
    for i in range(n):
        for j in range(n):
            if i != j and not A[i][j]:
                ans += 1
    print(ans // 2)
