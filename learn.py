class Union:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.size = [1] * n
    
    def find(self, i):
        if self.p[i] != i:
            self.p[i] = self.find(self.p[i])
        return self.p[i]
    
    def link(self, i, j):
        i, j = self.find(i), self.find(j)
        if self.size[i] < self.size[j]:
            i, j = j, i
        self.p[j] = i
        self.size[i] += self.size[j]