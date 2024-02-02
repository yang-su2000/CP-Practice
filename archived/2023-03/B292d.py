class Union:
    def __init__(self, n):
        self.ls = [i for i in range(n)]
        self.vsize = [1] * n
        self.esize = [0] * n
        
    def find(self, i):
        if self.ls[i] != i:
            self.ls[i] = self.find(self.ls[i])
        return self.ls[i]
    
    def link(self, i, j):
        i = self.find(i)
        j = self.find(j)
        if i != j:
            if self.vsize[i] > self.vsize[j]:
                i, j = j, i
            self.ls[i] = j
            self.vsize[j] += self.vsize[i]
            self.esize[j] += self.esize[i] + 1
        else:
            self.esize[j] += 1

n, m = [int(i) for i in input().split()]
U = Union(n)
for _ in range(m):
    u, v = [int(i) for i in input().split()]
    u -= 1
    v -= 1
    U.link(u, v)
for i in range(n):
    j = U.find(i)
    if U.vsize[j] != U.esize[j]:
        print('No')
        exit(0)
print('Yes')