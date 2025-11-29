import sys
input = lambda: sys.stdin.buffer.readline()
fprint = lambda s: sys.stdout.write(str(s) + "\n")

grid = [[0] * 2002 for _ in range(2002)]
one = [[0] * 2002 for _ in range(2002)]
n = int(input())

clouds = [tuple()] * n

for i in range(n):
    r1, r2, c1, c2 = map(int, input().split())
    clouds[i] = (r1, r2, c1, c2)
    grid[r1][c1] += 1
    grid[r1][c2+1] -= 1
    grid[r2+1][c1] -= 1
    grid[r2+1][c2+1] += 1

for i in range(2002):
    for j in range(1, 2002):
        grid[i][j] += grid[i][j-1]

for j in range(2002):
    for i in range(1, 2002):
        grid[i][j] += grid[i-1][j]

base = 0
for i in range(1, 2001):
    for j in range(1, 2001):
        if grid[i][j] == 1:
            one[i][j] = 1
        elif grid[i][j] == 0:
            base += 1

for i in range(2002):
    for j in range(1, 2002):
        one[i][j] += one[i][j-1]

for j in range(2002):
    for i in range(1, 2002):
        one[i][j] += one[i-1][j]

for r1, r2, c1, c2 in clouds:
    cnt = one[r2][c2] - one[r1-1][c2] - one[r2][c1-1] + one[r1-1][c1-1]
    fprint(base + cnt)
