from collections import defaultdict

n, x = [int(c) for c in input().split()]
arr = [int(c) for c in input().split()]

s = [[arr[i],i] for i in range(len(arr))]
s.sort()

i=0
j=len(arr)-1
flag = 1
while i<j:
    if s[i][0] + s[j][0] == x:
        flag = 0
        print(s[i][1]+1,s[j][1]+1)
        break
    elif s[i][0] + s[j][0] < x:
        i+=1
    else:
        j-=1
if flag:
    print("IMPOSSIBLE")