from sortedcontainers import SortedDict

def dfs(tree, h, i):
    cur = 0
    for child in tree[i]:
        cur = max(cur, dfs(tree, h, child))
    cur += 1
    h[i] = cur
    return cur

def foo(n, k, p):
    tree = {i: set() for i in range(1, n + 1)} # i -> [childs]
    ptree = {i+2: parent for i, parent in enumerate(p)} # i -> parent
    for i, parent in enumerate(p):
        tree[parent].add(i + 2)
    # print(tree.items())
    h = SortedDict() # i -> height
    dfs(tree, h, 1)
    # print(h.items())
    ans = h[1]
    while k:
        ans2 = ans
        target = None
        for i, height in h.items():
            cur = max(ans - height, height + 1)
            if cur <= ans2:
                ans2 = cur
                target = i
        # print(ans2, target)
        tree[ptree[target]].remove(target)
        tree[1].add(target)
        ptree[target] = 1
        dfs(tree, h, 1)
        ans = h[1]
        k -= 1
    return ans
            

t = int(input())
for _ in range(t):
    n, k = [int(i) for i in input().split()]
    p = [int(i) for i in input().split()]
    print(foo(n, k, p))