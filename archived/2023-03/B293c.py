h, w = [int(i) for i in input().split()]
mat = []
for i in range(h):
    row = [int(i) for i in input().split()]
    mat.append(row)
ans = 0

def dfs(i, j, vis):
    global mat, ans, h, w
    if i == h-1 and j == w-1:
        if mat[i][j] not in vis:
            ans += 1
        return
    if i < h-1:
        if mat[i][j] not in vis:
            vis.add(mat[i][j])
            dfs(i+1, j, vis)
            vis.remove(mat[i][j])
    if j < w-1:
        if mat[i][j] not in vis:
            vis.add(mat[i][j])
            dfs(i, j+1, vis)
            vis.remove(mat[i][j])

dfs(0, 0, set())
print(ans)