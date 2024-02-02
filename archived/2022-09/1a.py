def foo(n, m, a):
    i = n // a + (1 if n % a else 0)
    j = m // a + (1 if m % a else 0)
    return i * j

ls = [int(i) for i in input().split()]
n, m, a = ls[0], ls[1], ls[2]
print(foo(n, m, a))