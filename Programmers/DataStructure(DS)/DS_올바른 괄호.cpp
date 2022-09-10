#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s) {
    bool answer = true;
    stack<char> stk;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            stk.push(s[i]);
            continue;
        }
        if(stk.size()) stk.pop();
        else return false;
    }
    if(stk.size()) answer = false;

    return answer;
}
