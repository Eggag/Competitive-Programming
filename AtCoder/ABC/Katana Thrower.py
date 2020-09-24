n, h = map(int, input().split())
a = []
b = []
for i in range(n):
    a1, b1 = map(int, input().split())
    a.append(a1)
    b.append(b1)
ind = n - 1
a.sort()
b.sort()
ans = 0
while h > 0:
    if(ind >= 0 and b[ind] > a[n - 1]):
        h -= b[ind]
        ind -= 1
        ans += 1
    else:
        ans += (h + a[n - 1] - 1) // a[n - 1]
        h = 0
print(ans)

