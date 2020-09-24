import sys

n, y = map(int, input().split())
y /= 1000
for i in range(n + 1):
    for j in range(n + 1):
        k = n - i - j
        if(k >= 0 and (i * 10 + j * 5 + k) == y):
            print(i, j, k)
            exit(0)
print("-1 -1 -1")
