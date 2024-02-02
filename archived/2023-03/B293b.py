n = int(input())
ls = [int(i)-1 for i in input().split()]
flags = [False] * n
for i in range(n):
    if not flags[i]:
        flags[ls[i]] = True
count = 0
ans = []
for i in range(n):
    if not flags[i]:
        count += 1
        ans.append(i+1)
print(count)
for i in range(len(ans)):
    print(ans[i], end=' \n'[i == len(ans)-1])