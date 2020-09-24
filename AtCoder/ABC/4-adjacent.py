n = int(input())
a = list(map(int, input().split()))
cnt2 = 0
cnt4 = 0
for i in range(n):
    if(a[i] % 4 == 0):
        cnt4 += 1
    elif(a[i] % 2 == 0):
        cnt2 += 1

if((cnt4 * 2 + 1) >= n or cnt2 >= (n - (cnt4 * 2 + 1) + 1)):
    print("Yes")
else:
    print("No")
