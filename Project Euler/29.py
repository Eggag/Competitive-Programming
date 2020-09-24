ans = []
for a in range(2, 101):
    for b in range(2, 101):
        r = a ** b
        if r not in ans:
            ans.append(r)
print(len(ans))
