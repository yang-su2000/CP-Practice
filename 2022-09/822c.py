from functools import reduce

def foo(n):
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if not n % i)))
    
def bar(n, s, f):
    ans = 0
    invalid_set = set()
    for i in range(n):
        cur_set = f[i]
        if s[i] == '2':
            break
        elif s[i] == '0':
            ans += min(cur_set - invalid_set)
        else:
            invalid_set |= cur_set
    return ans

t = int(input())
ns = []
ss = []
max_f = 0
for _ in range(t):
    n = int(input())
    ns.append(n)
    s = input()
    c = n-1
    while c >= 0:
        if s[c] == '1':
            c -= 1
        else:
            break
    max_f = max(max_f, c+3)
    s = s[:c+1] + '2' * (n-c-1)
    ss.append(s)
factors = [foo(n) for n in range(1, max_f)]
for n, s in zip(ns, ss):
    print(bar(n, s, factors))
