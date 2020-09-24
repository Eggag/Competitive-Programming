n, l = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
maxDist = max(a[0], l - a[n - 1])
for i in range(n - 1):
    if((a[i + 1] - a[i]) / 2 > maxDist):
        maxDist = (a[i + 1] - a[i]) / 2
print(maxDist)
    
