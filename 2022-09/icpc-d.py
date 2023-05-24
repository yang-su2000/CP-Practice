def foo(n, A, B, C):
    ls = C
    ans = [0] * n
    modulo = 998244353
    for k in range(n):
        for i in range(n):
            ls[i] = ls[i] * (A[i] + B[k]) % modulo
        ans[k] = sum(ls) % modulo
    return ans

n = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]
for i, val in enumerate(foo(n, A, B, C)):
    if i + 1 < n:
        print(val, end=' ')
    else:
        print(val)