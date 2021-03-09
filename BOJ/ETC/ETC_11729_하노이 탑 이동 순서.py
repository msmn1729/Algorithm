n = int(input())


def hanoi(n, start, by, to):
    if n == 1:
        print(start, to)
        return
    hanoi(n - 1, start, to, by)
    print(start, to)
    hanoi(n - 1, by, start, to)


print(2 ** n - 1)
hanoi(n, 1, 2, 3)
