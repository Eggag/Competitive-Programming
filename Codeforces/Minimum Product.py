def solve():
    a, b, x, y, n = map(int, input().split())
    a1 = a
    b1 = b
    x1 = x
    y1 = y
    n1 = n
    if b > a:
        c = b
        b = a
        a = c
        d = x
        x = y
        y = d
    rem = b - y
    if rem <= n:
        n -= rem
        b = y
    else:
        b -= n
        n = 0
    a -= n
    if b1 <= a1:
        c1 = b1
        b1 = a1
        a1 = c1
        d1 = x1
        x1 = y1
        y1 = d1
    rem1 = b1 - y1
    if rem1 <= n1:
        n1 -= rem1
        b1 = y1
    else:
        b1 -= n1
        n1 = 0
    a1 -= n1
    print(min(max(a1, x1) * max(b1, y1), max(a, x) * max(b, y)))


t = int(input())
for i in range(t):
    solve()
