a, x, m = [int(i) for i in input().split()]
if a == 1:
    print(x % m)
    exit(0)
ax = pow(a, x, m * (a-1))
ax = (ax - 1) % (m * (a-1))
print(ax // (a-1))
