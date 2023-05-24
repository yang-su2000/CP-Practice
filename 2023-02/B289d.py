if __name__ == "__main__":
    n = int(input())
    A = [int(i) for i in input().split()]
    m = int(input())
    B = [int(i) for i in input().split()]
    X = int(input())
    dp = [0] * (X + 1)
    for b in B:
        dp[b] = -1
    dp[0] = 1
    for i in range(1, X+1):
        if dp[i] == -1:
            continue
        for a in A:
            if i >= a and dp[i-a] == 1:
                dp[i] = 1
                break
    print('Yes' if dp[X] == 1 else 'No')
    