def isrange(i, j, n, m):
    return 0 <= i < n and 0 <= j < m

def foo(n, m):
    for i in range(n):
        for j in range(m):
            if not (isrange(i-2, j-1, n, m) or isrange(i-1, j-2, n, m) or isrange(i-2, j+1, n, m) or isrange(i-1, j+2, n, m) \
                or isrange(i+2, j-1, n, m) or isrange(i+1, j-2, n, m) or isrange(i+2, j+1, n, m) or isrange(i+1, j+2, n, m)):
                return i+1, j+1
    return 1, 1
            

t = int(input())
for _ in range(t):
    n, m = [int(i) for i in input().split()]
    i, j = foo(n, m)
    print(i, j)