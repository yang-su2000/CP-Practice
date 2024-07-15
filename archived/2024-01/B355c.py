n, q = [int(i) for i in input().split()]
ls = [(i, 0) for i in range(1, n + 1)][::-1]
for _ in range(q):
    tag, val = input().split()
    if tag == '1':
        dx, dy = None, None
        if val == 'L':
            dx, dy = -1, 0
        elif val == 'R':
            dx, dy = 1, 0
        elif val == 'U':
            dx, dy = 0, 1
        elif val == 'D':
            dx, dy = 0, -1
        x, y = ls[-1]
        ls.append((x + dx, y + dy))
    else:
        val = int(val)
        x, y = ls[-val]
        print(f"{x} {y}")