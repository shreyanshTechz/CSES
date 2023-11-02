n, m, k = [int(c) for c in input().split()]
x = [int(p) for p in input().split()]
d = [int(q) for q in input().split()]
ans = 0
x.sort()
d.sort()
i = j = 0
while i < len(x):
    while j < len(d) and d[j] < x[i] - k:
        j += 1
    if j >= len(d):
        break
    if abs(x[i] - d[j]) <= k:
        ans += 1
        i += 1
        j += 1
    else:
        i += 1
print(ans)
