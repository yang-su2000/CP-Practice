from collections import deque

def foo(n, a, b):
    l1 = []
    l2 = []
    for i in range(n):
        if a[i] == 0:
            l1.append(b[i])
        else:
            l2.append(b[i])
    l1.sort()
    l2.sort()
    ans = 0
    while l1 and l2:
        ans += 2 * (l1.pop() + l2.pop())
    if l1:
        ans += sum(l1)
    elif l2:
        ans += sum(l2)
    else:
        ans -= min(b)
    return ans

t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    print(foo(n, a, b))