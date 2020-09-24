t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if a > b:
        print((a - b + 9) // 10)
    else:
        print((b - a + 9) // 10)
