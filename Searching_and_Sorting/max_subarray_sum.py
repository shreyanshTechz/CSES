n = [int(c) for c in input().split()]
arr = [int(c) for c in input().split()]

ans = arr[0]
curr = arr[0]
for i in range(1,len(arr)):
    curr = max(arr[i],curr + arr[i])
    ans = max(ans,curr)
    # print(ans,end=" ")
print(ans)