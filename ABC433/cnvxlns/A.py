x, y, z = map(int, input().split())


a = (x - z * y) / (z - 1)

if a == int(a) and a >= 0:
    print("Yes")
else:
    print("No")