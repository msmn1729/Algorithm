n = int(input())

cnt = 0
tmp_n = n

while True:
    jari_sum = tmp_n // 10 + tmp_n % 10
    new_n = tmp_n % 10 * 10 + jari_sum % 10
    cnt += 1
    if n == new_n:
        print(cnt)
        break
    tmp_n = new_n
