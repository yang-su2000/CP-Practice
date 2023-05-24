n = int(input())
ans = 0
for _ in range(n):
    s = input()
    if s == 'For':
        ans += 1
if ans > n // 2:
    print('Yes')
else:
    print('No')