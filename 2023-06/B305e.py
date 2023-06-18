# import math, heapq, bisect, itertools, functools
from heapq import *

# python sample.py < input

if __name__ == '__main__':
    n, m, k = map(int, input().split())
    A = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        if a == b:
            continue
        A[a].append(b)
        A[b].append(a)
    H = [0] * n
    cur = []
    for _ in range(k):
        v, h = map(int, input().split())
        h += 1
        v -= 1
        heappush(cur, (-h, v))
        H[v] = h
    while cur:
        h, node = heappop(cur)
        h = -h
        if h < H[node]:
            continue
        for child in A[node]:
            if H[child] < h-1:
                H[child] = h-1
                heappush(cur, (1-h, child))
    l = sum(val > 0 for val in H)
    print(l)
    count = 0
    for i, val in enumerate(H):
        if val:
            count += 1
            print(i+1, end=' \n'[count == l])
        
    