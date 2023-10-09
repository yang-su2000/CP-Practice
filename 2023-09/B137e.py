import math
from itertools import product

def h(A1, A2):
    g = math.gcd(A1, A2)
    lcm = ((A1 * A2) // g)
    return N // lcm

MOD = 998244353
N, A1, A2, A3 = map(int, input().split())

# dp[i][2^3 flag for A1, A2, A3][remainder 1][remainder 2][remainder 3] = number of tuples (x1, x2, x3) such that
# 0 <= X1, X2, X3 < 2^i
# X1 xor X2 xor X3 = 0
# flag: whether X1, X2, X3 <= (N & (2^i - 1))
# remainder: the remainder of X1, X2, X3 mod A1, A2, A3
dp = [[[[[0 for _ in range(A3)] for _ in range(A2)] for _ in range(A1)] for _ in range(8)] for _ in range(64)]
dp[0][0][0][0][0] = 1

# pre-compute bit-wise xor result for n, f, x
# n: each bit of N
# f: each bit of 
D = {}
D[(0, 0, 0)] = 0
D[(0, 1, 0)] = 1
D[(0, 0, 1)] = 1
D[(0, 1, 1)] = 1
D[(1, 0, 0)] = 0
D[(1, 1, 0)] = 0
D[(1, 0, 1)] = 0
D[(1, 1, 1)] = 1

# iterate through each possible bit of N
for i in range(63):
    n = (N >> i) & 1
    k = pow(2, i)
    p1 = k % A1
    p2 = k % A2
    p3 = k % A3
    for x1, x2, x3 in product([0, 1], repeat=3): # iterate through each possible previous choosing combo, i.e. whether to pick each X
        y = x1 ^ x2 ^ x3
        for f1, f2, f3 in product([0, 1], repeat=3): # iterate through each possible previous xor combo, i.e. whether X xor n on previous bit
            f = 4 * f1 + 2 * f2 + f3
            nf = 4 * D[(n, f1, x1)] + 2 * D[(n, f2, x2)] + D[(n, f3, x3)] # calculate X xor n result on current bit
            for r1, r2, r3 in product(range(A1), range(A2), range(A3)): # iterate through each possible remainders from previous bit
                # calculate each possible current remainder
                nr1 = (p1 * x1 + r1) % A1
                nr2 = (p2 * x2 + r2) % A2
                nr3 = (p3 * x3 + r3) % A3
                # assign current state if current choosing combo is valid
                dp[i + 1][nf][nr1][nr2][nr3] += dp[i][f][r1][r2][r3] * (1 - y)
                dp[i + 1][nf][nr1][nr2][nr3] %= MOD

ans = dp[63][0][0][0][0]
ans -= 1  # 0 0 0
ans -= h(A1, A2)
ans -= h(A2, A3)
ans -= h(A3, A1)
ans %= MOD
print(ans)