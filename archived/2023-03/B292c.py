from math import sqrt

n = int(input())
ls = [0] * (n + 1)
for i in range(1, n + 1):
    fcount = 0
    for f in range(1, int(sqrt(i)) + 1):
        if i % f == 0:
            fcount += 2
            if i == f * f:
                fcount -= 1
    ls[i] = fcount
ans = 0
for i in range(1, n + 1):
    ans += ls[i] * ls[n - i]
print(ans)