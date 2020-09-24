n = int(input())
a = []
for i in range(n):
    c = int(input())
    a.append(c)
a.sort()
ans = 1
for i in range(1, n):
    if(a[i] != a[i - 1]):
        ans += 1
print(ans)
