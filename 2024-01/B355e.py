from heapq import *

class Union:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.size = [1] * n
    
    def find(self, i):
        if self.p[i] != i:
            self.p[i] = self.find(self.p[i])
        return self.p[i]
    
    def link(self, i, j):
        i, j = self.find(i), self.find(j)
        if self.size[i] < self.size[j]:
            i, j = j, i
        self.p[j] = i
        self.size[i] += self.size[j]

n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
A = [[] for _ in range(n)]
Aij = []
U = Union(n)
for _ in range(m):
    u, v = [int(i) for i in input().split()]
    u -= 1
    v -= 1
    if a[u] == a[v]:
        U.link(u, v)
    else:
        Aij.append((u, v))
for u, v in Aij:
    u = U.find(u)
    v = U.find(v)
    if a[u] < a[v]:
        A[u].append(v)
    elif a[v] < a[u]:
        A[v].append(u)
ds = [0] * n
cur = [(0, -1, U.find(0))] # value, -d, node
ds[U.find(0)] = 1
while cur:
    _, d, node = heappop(cur)
    d = -d
    if d != ds[node]:
        continue
    for child in A[node]:
        if d + 1 <= ds[child]:
            continue
        ds[child] = d + 1
        heappush(cur, (a[child], -(d + 1), child))
    # print(cur)
# print(A, ds)
print(ds[U.find(n - 1)])