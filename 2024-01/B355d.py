n = int(input())
ls = [[-1] * n for _ in range(n)]
d = [(0, 1), (1, 0), (0, -1), (-1, 0)]
di = 0
x, y = 0, 0

def valid(a, b):
    return 

for i in range(1, n * n):
    ls[x][y] = i
    x2, y2 = x + d[di][0], y + d[di][1]
    if (not (0 <= x2 < n and 0 <= y2 < n)) or ls[x2][y2] != -1:
        di = (di + 1) % len(d)
        x2, y2 = x + d[di][0], y + d[di][1]
    x, y = x2, y2
    # print(x, y)
for i in range(n):
    for j in range(n):
        if ls[i][j] != -1:
            print(ls[i][j], end="")
        else:
            print('T', end="")
        if j < n - 1:
            print(end=" ")
        else:
            print()