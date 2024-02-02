# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    n = int(input())
    A = [[] for _ in range(n)]
    for _ in range(n-1):
        u, v = [int(i)-1 for i in input().split()]
        A[u].append(v)
        A[v].append(u)
    # print(A)
    ans = []
    
    # def bfs(node, parent, level):
    #     global ans, A
    #     if level % 3 == 1:
    #         ans.append(len(A[node]))
    #     for child in A[node]:
    #         if child == parent:
    #             continue
    #         bfs(child, node, level + 1)
    
    level = 0
    vis = [False] * n
    cur = []
    for i in range(n):
        if len(A[i]) == 1:
            vis[i] = True
            cur.append(i)
            break
    while cur:
        nxt = []
        for node in cur:
            if level % 3 == 1:
                ans.append(len(A[node]))
            for child in A[node]:
                if vis[child]:
                    continue
                vis[child] = True
                nxt.append(child)
        cur = nxt
        level += 1
    ans.sort()
    for i in range(len(ans)):
        print(ans[i], end=' \n'[i == len(ans)-1])