ar = [0 for i in range(10001)]

for i in range(1, 10001):
    new_num = sum(map(int, str(i))) + i
    if new_num <= 10000:
        ar[new_num] = 1

for i in range(1, 10001):
    if ar[i] == 0:
        print(i)