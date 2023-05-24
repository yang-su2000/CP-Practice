n, m = [int(i) for i in input().split()]
s = set()
nls = []
for _ in range(n):
    nls.append(input()[3:])
for _ in range(m):
    s.add(input())
ans = 0
for item in nls:
    if item in s:
        ans += 1
print(ans)