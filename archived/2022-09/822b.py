def foo(n):
    ls = [[0 for _ in range(i+1)] for i in range(n)]
    for i in range(n):
        ls[i][0] = ls[i][-1] = 1
    return ls
            

t = int(input())
ns = []
for _ in range(t):
    n = int(input())
    ns.append(n)
ls = foo(max(ns))
for n in ns:
    for i in range(n):
        print(' '.join([str(j) for j in ls[i]]))
