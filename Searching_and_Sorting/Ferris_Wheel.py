n, k = [int(c) for c in input().split()]
arr = [int(x) for x in input().split()]
ans = 0
arr.sort()
# print(arr)
i = 0
j = n - 1
while j >= i:
    if arr[j] + arr[i] <= k:
        i += 1
        j -= 1
        ans += 1
    else:
        ans += 1
        j -= 1
print(ans)


# print(ans+1)
