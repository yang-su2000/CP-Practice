n, m = [int(i) for i in input().split()]
ls = [int(i) for i in input().split()]
ans = []
i = 0
l = 1
r = 1
while r <= n:
    if i < m:
        if ls[i] == r:
            i += 1
            r += 1
        else:
            for num in range(r, l-1, -1):
                ans.append(num)
            l = r+1
            r = l
    else:
        for num in range(r, l-1, -1):
            ans.append(num)
        l = r+1
        r = l
for i in range(len(ans)):
    print(ans[i], end=" \n"[i == len(ans)-1])