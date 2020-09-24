n = int(input())
s = str(input())
mn = int(s)
pos = []
cnt = 0
for i in range(n // 2, n):
    if(cnt < 3 and s[i] != '0'):
        pos.append(i)
        cnt += 1
cnt = 0
for i in range(n // 2 - 1, 0, -1):
    if(cnt < 3 and s[i] != '0'):
        pos.append(i)
        cnt += 1
for i in pos:
    s1 = s[:i]
    s2 = s[i:]
    n1 = int(s1)
    n2 = int(s2)
    if((n1 + n2) < mn):
        mn = n1 + n2
print(mn)
