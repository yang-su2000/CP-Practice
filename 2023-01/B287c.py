from collections import deque

n, m = [int(i) for i in input().split()]
if m != n-1:
    print('No')
    exit(0)
A = [[] for _ in range(n)]
B = [False] * n
for _ in range(m):
    a, b = [int(i)-1 for i in input().split()]
    A[a].append(b)
    A[b].append(a)
count = 1
cur = deque([(0, -1)]) # cur, parent
B[0] = True
while cur:
    node, parent = cur.pop()
    for child in A[node]:
        if child == parent or B[child]:
            continue
        cur.appendleft((child, node))
        count += 1
        B[child] = True
print('Yes') if count == n else print('No')