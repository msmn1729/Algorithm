import collections

n, m = map(int, input().split())
order = list(map(int, input().split()))

ar = [i for i in range(1, n + 1)]
dq = collections.deque(ar)

ans = 0
for i in order:
    if dq.index(i) <= len(dq) // 2:  # 왼쪽
        while dq[0] != i:
            dq.rotate(-1)
            ans += 1
        dq.popleft()
    else:  # 오른쪽
        while dq[0] != i:
            dq.rotate(1)
            ans += 1
        dq.popleft()

print(ans)
