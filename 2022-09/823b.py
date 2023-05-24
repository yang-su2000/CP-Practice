def foo(n, X, T):
    pos = float('-inf')
    neg = float('-inf')
    for i in range(n):
        pos = max(pos, T[i] + X[i])
        neg = max(neg, T[i] - X[i])
    return pos - (pos + neg) / 2.0

t = int(input())
for _ in range(t):
    n = int(input())
    X = [int(i) for i in input().split()]
    T = [int(i) for i in input().split()]
    print(foo(n, X, T))