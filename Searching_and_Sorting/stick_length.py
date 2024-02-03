n = [int(c) for c in input().split()]
arr = [int(c) for c in input().split()]

arr.sort()
ans = 0
mid = arr[len(arr)//2]
for i in range(len(arr)):
    if i!=len(arr)//2:
        ans += abs(arr[i] - mid)
print(ans)