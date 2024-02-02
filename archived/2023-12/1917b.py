t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    st = set()
    ans = 0
    for c in s:
        st.add(c)
        ans += len(st)
    print(ans)