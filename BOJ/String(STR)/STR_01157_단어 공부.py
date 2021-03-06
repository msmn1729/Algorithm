word = input().upper()
unique_word = set(word)

ar = []
mx = 0
for i in unique_word:
    ar.append(word.count(i))
    if mx < word.count(i):
        mx = word.count(i)
        ans = i

if ar.count(mx) > 1:
    print('?')
else:
    print(ans)
