def foo(n):
    dp = [[[[0] * 2 for _ in range(2)] for _ in range(n)] for _ in range(n)]
    dp[1][0][0][0] = 1
    dp[1][0][0][1] = 2
    dp[1][0][1][0] = 2
    dp[1][0][1][1] = 2
    
    dp[0][1][0][0] = 2
    dp[0][1][0][1] = 2
    dp[0][1][1][0] = 1
    dp[0][1][1][1] = 2
    
    for o in range(1, n):
        for e in range(1, n):
            cur = dp[o][e]
            for i in range(2):
                for j in range(2):
                    cur[i][j] = max(cur[i][j], dp[o-1][e][j][i-1])
                    cur[i][j] = max(cur[i][j], dp[o][e-1][j-1][i])
    return dp

t = int(input())
n = 6
dp = foo(n) # [o, e, i, j] with o of odds, e of evens, the result of the game if now Alice is i and Bob is j
for o in range(n):
    for e in range(n):
        print(o, e, dp[o][e])
for _ in range(t):
    n = int(input())
    ls = [int(i) for i in input().split()]
    o, e = 0, 0
    for i in ls:
        if i % 2:
            o += 1
        else:
            e += 1
    print('Alice' if dp[o][e][0][0] == 2 else 'Bob')