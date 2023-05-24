from math import comb

def foo(N):
    modulo = 998244353 
    d = {2: (1, 0, 1)} # n -> (win, lose, draw)
    for n in range(4, N+1, 2):
        plose, pwin, pdraw = d[n-2]
        k = n//2
        win = (comb(n-1, k-1) + pwin) % modulo
        lose = (comb(n-2, k) + plose) % modulo
        draw = pdraw
        d[n] = (win, lose, draw)
    return d
            

t = int(input())
ns = []
for _ in range(t):
    n = int(input())
    ns.append(n)
nmax = max(ns)
d = foo(nmax)
for n in ns:
    win, lose, draw = d[n]
    print(win, lose, draw)