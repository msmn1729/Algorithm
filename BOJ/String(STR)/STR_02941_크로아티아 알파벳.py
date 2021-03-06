word = input()
ar = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for i in ar:
    word = word.replace(i, '*')

print(len(word))
