def solution(s):
    ls = list(map(int, s.split(' ')))
    print(min(ls), max(ls))
    answer = str(min(ls)) + ' ' + str(max(ls))
    return answer
