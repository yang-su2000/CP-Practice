# Competitive-Programming-Practice

- [LeetCode](https://leetcode.com/shinever/) target: [2200 - 2299 - 2400] (Orange -> Red)
- [CodeForces](https://codeforces.com/profile/shinever) target: [1600 - 1664 - 1900] (Expert -> Candidate Master)
- [AtCoder](https://atcoder.jp/users/shinever) target: [600 - 718 - 1200] (Brown -> Green)
- [CodeChef](https://www.codechef.com/users/shinever) target: [1600 - 1610 - 2000] (Div.2 -> Div.1)

### Notes

- "ad-hoc" (思维, not really algorithm but tricky) algorithms
    - "conclusion" (结论): by some observation, the question can be easily reduced to some base case solutions (typically the solution is either 1 or 2 based on the input)
    - "divide and conquer" (分类讨论): not binary search, but the strategy of splitting question into different conditions and solve it under these conditions
    - "transfer" (转换): need to manually establish some style of strategy to transfer the question to a simpler case
    - "constructive algorithm" (构造): this is hard to summarize, need more practice
    - "maintain" (维护): need to preprocess some array and then modify it as we loop through something
    - etc.
- (actual) algorithms
    - math (prime, number theory)
    - greedy (string, array)
    - tree: binary-index tree (BIT, or Fenwick Tree), segment tree, MST
    - dp: multidim-dp (memo, state-compression), bit-dp, tree-dp, DAG-dp
    - graph
    - etc.

### Favorite

**1400**

- bit-Trie https://codeforces.com/contest/1847/problem/C
    - maximum xor subarray
    - https://cppsecrets.com/users/16074971069712111497109109494864103109971051084699111109/Maximum-XOR-subarray.php

### Failed

- if failed because of mis-interpretation of algorithm type, denote as [A]

**N/A**

- pigeonhole principle https://codeforces.com/contest/1994/problem/D

**1000**

- math + greedy https://codeforces.com/problemset/problem/1715/B

**1300**

- constructive algorithm + math (prime) https://codeforces.com/contest/1864/problem/C

**1400**

- "divide and conquer" https://codeforces.com/problemset/problem/1463/B

**1500**

- brute force + "divide and conquer" https://codeforces.com/problemset/problem/1379/B
- constructive algorithm + "divide and conquer" https://codeforces.com/problemset/problem/1710/A
- string greedy https://codeforces.com/contest/1925/problem/C

**1600**

- presum + dp + "maintain" https://codeforces.com/problemset/problem/1677/A
- graph + greedy https://codeforces.com/problemset/problem/1476/C

**1800**

- [A] bipartite graph https://codeforces.com/problemset/problem/173/B
- greedy + "transfer" https://codeforces.com/problemset/problem/1845/D
- math (number theory) https://codeforces.com/contest/1848/problem/C

**2000**

- [A] math (number theory, euler's totient) + "maintain" https://codeforces.com/contest/1900/problem/D
    - [TODO] still not fully understand why `gcd(a, b) = sum(phi(d) for d in both divisor(a) and divisor(b))`