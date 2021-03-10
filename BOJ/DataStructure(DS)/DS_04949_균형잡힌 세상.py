while True:
    s = input()
    if s == '.':
        break
    stack = []
    flag = 0
    for i in s:
        if i == '(' or i == '[':
            stack.append(i)
        elif i == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                print('no')
                flag = 1
                break
        elif i == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                print('no')
                flag = 1
                break
    if flag == 1:
        continue
    if len(stack) == 0:
        print('yes')
    else:
        print('no')
