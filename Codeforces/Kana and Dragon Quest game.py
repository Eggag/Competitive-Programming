t = int(input())
for _ in range(t):
    x, n, m = map(int, input().split())
    while(n and ((x // 2) + 10) < x):
        n -= 1
        x = (x // 2) + 10
    if((m * 10) >= x): print("YES")
    else: print("NO")
