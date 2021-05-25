#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> stk;

    for(int i=0; i<s.size(); i++) {
        if(stk.size() && stk.top() == s[i]) {
            stk.pop();
            continue;
        }
        stk.push(s[i]);
    }
    if(stk.empty()) return 1;
    return 0;
}