def bt(ls, idx, cur):
    global ans
    if idx == len(ls):
        # print(cur)
        if len(cur) == n:
            ans += 1
        return
    bt(ls, idx+1, cur)
    bt(ls, idx+1, cur | ls[idx])
  
if __name__ == "__main__":
    n, m = [int(i) for i in input().split()]
    ls = []
    for _ in range(m):
        c = int(input())
        s = set([int(i) for i in input().split()])
        ls.append(s)
    ans = 0
    bt(ls, 0, set())
    print(ans)