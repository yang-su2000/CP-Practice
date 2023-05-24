# python sample.py < input.txt

if __name__ == '__main__':
    n = int(input())
    s = input()
    ans = ''
    i = 0
    while i < n:
        if i < n - 1 and s[i:i+2] == 'na':
            ans += 'nya'
            i += 2
        else:
            ans += s[i]
            i += 1
    print(ans)