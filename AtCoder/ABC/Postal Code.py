a, b = map(int, input().split())
s = str(input())
lst = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
for i in range(len(s)):
    if(i != a):
        if(s[i] not in lst):
            print("No");
            exit(0)
    else:
        if(s[i] != '-'):
            print("No");
            exit(0)
print("Yes")
