from decimal import Decimal, getcontext


getcontext().prec = 50

N = int(input())
data = input().split()
a = list(map(Decimal, data[0:N]))

ans = Decimal(0)
for i in range(N):
    for j in range(i):
        cnt = Decimal(0)
        if a[j] <= a[i]:
            cnt = (a[j] * (a[j] - 1)) // 2
        else:
            cnt = (a[i] * (a[i] - 1)) // 2 + (a[j] - a[i]) * a[i]
        ans += cnt / (a[j] * a[i])

print(f"{ans:.6f}")
