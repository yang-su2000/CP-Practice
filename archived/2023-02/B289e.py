if __name__ == "__main__":
    t = int(input())
    while t:
        t -= 1
        n, m = [int(i) for i in input().split()]
        C = [True if i == '1' else False for i in input().split()]
        A = [[] for _ in range(n)]
        for _ in range(m):
            u, v = [int(i) for i in input().split()]
            A[u-1].append(v-1)
            A[v-1].append(u-1)
        if C[0] == C[-1]:
            print(-1)
            continue
        # print(A, C)
        vis = [[False] * n for _ in range(n)]
        vis[0][-1] = True
        q = [(0, n-1)]
        ans = 0
        # print(q)
        while not vis[-1][0] and q:
            q2 = []
            for u, v in q:
                # 0, 1
                for color in (False, True):
                    n0 = []
                    n1 = []
                    for child in A[u]:
                        if C[child] == color:
                            n0.append(child)
                    for child in A[v]:
                        if C[child] != color:
                            n1.append(child)
                    for i in n0:
                        for j in n1:
                            if not vis[i][j]:
                                vis[i][j] = True
                                q2.append((i, j))
                    # print(n0, n1)
            q = q2
            # print(q)
            ans += 1
        print(ans if vis[-1][0] else -1)
        