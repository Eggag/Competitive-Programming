fib = []
fib.append(1)
fib.append(1)
ind = 2
p = 1
while(1):
    p = fib[ind - 1] + fib[ind - 2]
    fib.append(p)
    ind += 1
    if(len(str(p)) == 1000):
        print(ind)
        break
