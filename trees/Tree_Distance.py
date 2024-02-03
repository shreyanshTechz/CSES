from collections import defaultdict
import sys
# Get the current recursion limit
# print(sys.getrecursionlimit())
# Output: 1000

# Set a new recursion limit
sys.setrecursionlimit(15000)

SZ = 200005

n = int(input())
adj = defaultdict(list)
S = [0] * SZ
in_degree = [0] * SZ
out_degree = [0] * SZ

def dfs_in(u, p):
    global S
    S[u] = 1

    for v in adj[u]:
        if v != p:
            dfs_in(v, u)
            S[u] += S[v]
            in_degree[u] += in_degree[v] + S[v]

def dfs_out(u, p):
    global S
    store = 0
    for v in adj[u]:
        if v != p:
            store += in_degree[v] + S[v] * 2

    for v in adj[u]:
        if v != p:
            out_degree[v] = (out_degree[u] + 1 * (n - S[u] + 1)) + (store - (in_degree[v] + S[v] * 2))
            dfs_out(v, u)

for i in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

dfs_in(1, 0)
dfs_out(1, 0)

for i in range(1, n + 1):
    print(in_degree[i] + out_degree[i], end=" ")
