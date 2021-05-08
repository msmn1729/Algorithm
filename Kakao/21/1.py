def solution(s):
    num = ['zero' , 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    for i in range(len(num)):
        s = s.replace(num[i], str(i));
        
    return int(s)