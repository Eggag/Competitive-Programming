prime = [1 for i in range(int(1e5 + 10))]

def sieve(n):
    prime[0] = prime[1] = 0
    for i in range(2, n):
        for j in range(i + i, n, i):
            prime[j] = 0

q = int(input())
sieve(int(1e5))
cnt = []
for i in range(int(1e5)):
    if(i == 0):
        cnt.append(0)
    else:
        cnt.append(cnt[-1] + (prime[i] and prime[(i + 1) // 2]))
for i in range(q):
    l, r = map(int, input().split())
    print(cnt[r] - cnt[l - 1])
