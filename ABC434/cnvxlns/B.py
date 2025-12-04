n, m  = map(int, input().split())


a = [0] * (n + 1)
cnt = [0] * (n + 1)

for i in range(n):
    type, w = map(int, input().split())
    a[type] += w
    cnt[type] += 1

for type in range(1, m + 1):
    print(a[type] / cnt[type])