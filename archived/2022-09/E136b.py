def foo(n, d):
    a = [d[0]]
    for i in range(1, n):
        valid = set()
        if d[i] + a[i-1] >= 0:
            valid.add(d[i] + a[i-1])
        if a[i-1] - d[i] >= 0:
            valid.add(a[i-1] - d[i])
        if len(valid) == 1:
            a.append(list(valid)[0])
        else:
            return -1
    return a
            

t = int(input())
for _ in range(t):
    n = int(input())
    d = [int(i) for i in input().split()]
    ls = foo(n, d)
    if type(ls) is int:
        print(ls)
    else:
        for i in range(len(ls)):
            print(ls[i], end=' ' if i + 1 < len(ls) else '\n')