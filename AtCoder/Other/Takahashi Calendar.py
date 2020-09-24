m, d = map(int, input().split())
ans = 0
for i in range(1, m + 1):
    for j in range(1, d + 1):
        if(i == ((j % 10) * ((j - (j % 10)) / 10)) and (j % 10) >= 2 and ((j - (j % 10)) / 10 >= 2)):
            ans += 1
print(ans)
