h, w = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
ans = [[] for i in range(h)]
inc = True
r = 0
for i in range(n):
    while(a[i] > 0):
        if(inc):
            if(r <= h - 1):
                ans[r].append(i + 1)
                r += 1
            else:
                r = h - 1
                ans[r].append(i + 1)
                r -= 1
                inc = False
        else:
            if(r >= 0):
                ans[r].append(i + 1)
                r -= 1
            else:
                r = 0
                ans[r].append(i + 1)
                r += 1
                inc = True
        a[i] -= 1
for x in ans:
    for i in x:
        print(i, end = " ")
    print()

