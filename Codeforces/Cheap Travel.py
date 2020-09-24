n, m, a, b = map(int, input().split())
if((a * m) < b):
    print(a * n)
else:
    ans = b * (n // m)
    if((n % m) * a < b):
        ans += (n % m) * a
    else:
        ans += b
    print(int(ans))
