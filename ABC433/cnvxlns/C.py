s = input()

cnt = list()

prev = 'a'
count = 0

for i in s:
    if i == prev or prev == 'a':
        count += 1
    elif count != 0:
        cnt.append((prev, count))
        count = 1
    prev = i

cnt.append((prev, count))

prevkey, prevval = cnt[0]

ans = 0
for key, val in cnt:
    #print(key, val)
    if ord(key) - ord(prevkey) == 1:
        ans += min(val, prevval)
    prevkey = key
    prevval = val

print(ans)