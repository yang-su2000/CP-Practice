def foo(a, b, c, d):
    fa = []
    fi = 1
    while fi * fi <= a:
        if a % fi == 0:
            fa.append(fi)
            fa.append(a // fi)
        fi += 1
    fb = []
    fj = 1
    while fj * fj <= b:
        if b % fj == 0:
            fb.append(fj)
            fb.append(b // fj)
        fj += 1
    for i in fa:
        for j in fb:
            v1 = i * j
            v2 = a * b // i // j
            x = a + 1
            y = b + 1
            if x % v1 != 0:
                x += v1 - x % v1
            if y % v2 != 0:
                y += v2 - y % v2
            if x <= c and y <= d:
                return x, y
    return -1, -1
    

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        a, b, c, d = [int(i) for i in input().split()]
        num1, num2 = foo(a, b, c, d)
        print(num1, num2)