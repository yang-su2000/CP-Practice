# python sample.py < input.txt

if __name__ == '__main__':
    N, P, Q, R, S = [int(i) for i in input().split()]
    ls = [int(i) for i in input().split()]
    ls = ls[:P-1] + ls[R-1:S] + ls[Q:R-1] + ls[P-1:Q] + ls[S:]
    for i, num in enumerate(ls):
        print(num, end='')
        if i < len(ls) - 1:
            print(end=' ')
        else:
            print()