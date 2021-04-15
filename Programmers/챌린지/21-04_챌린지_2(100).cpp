#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;

    for(int i=0; i<s.size(); i++) {
        rotate(s.begin(), s.begin()+1, s.end());

        stack<char> stk;
        bool flag = false;
        for(char c: s) {
            if(c == ']') {
                if(stk.size() && stk.top() == '[') {
                    stk.pop();
                }
                else {
                    flag = true;
                    break;
                }
            }
            else if(c == '}') {
                if(stk.size() && stk.top() == '{') {
                    stk.pop();
                }
                else {
                    flag = true;
                    break;
                }
            }
            else if(c == ')') {
                if(stk.size() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    flag = true;
                    break;
                }
            }
            else stk.push(c);
        }
        if(flag == false && stk.size() == 0) answer++;
    }
    return answer;
}
