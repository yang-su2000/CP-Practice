n, q = [int(i) for i in input().split()]
ls = [0] * n
for _ in range(q):
    c, x = [int(i) for i in input().split()]
    x -= 1
    if c == 1:
        ls[x] += 1
    elif c == 2:
        ls[x] += 2
    else:
        print('Yes' if ls[x] >= 2 else 'No')