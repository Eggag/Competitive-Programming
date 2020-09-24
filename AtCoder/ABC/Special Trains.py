n = int(input())
c = []
s = []
f = []
for i in range(n - 1):
    a, b, d = map(int, input().split())
    c.append(a)
    s.append(b)
    f.append(d)
for i in range(n - 1):
    tot = s[i] + c[i] # time to wait + time to travel
    for j in range(i + 1, n - 1):
        if(tot >= s[j]):
            if(tot % f[j] == 0): tot += c[j]
            else: tot += f[j] - (tot % f[j]) + c[j]
        else:
            tot += (s[j] - tot) + c[j]
    print(tot)
print(0)
