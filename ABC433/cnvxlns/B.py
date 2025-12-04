n = int(input())

a = list(map(int, input().split()))

for i in range(0, len(a)):
    ans = -1
    for j in range(0, i):
        if a[j] > a[i]:
            ans = j + 1
    print(ans)
