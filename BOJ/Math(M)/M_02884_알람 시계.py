h, s = map(int, input().split())
if s < 45:
    h -= 1
    tmp = 45 - s
    s = 60 - tmp
else:
    s -= 45

if h == -1:
    h = 23
print(h, s)
