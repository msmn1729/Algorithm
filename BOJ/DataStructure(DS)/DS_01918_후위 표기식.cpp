#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1918 후위 표기식

int priority(char c) {
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string infix, postfix = "";
    stack<int> stk;
    cin >> infix;
    
    for(int i=0; i<infix.size(); i++) {
        char &c = infix[i];
        
        if(isalpha(infix[i])) postfix += c;
        else if(c == '(') stk.push(c);
        else if(c == ')') {
            while(stk.size() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            if(stk.size()) stk.pop(); //여는 괄호 제거
        }
        else {
            while(stk.size() && (priority(c) <= priority(stk.top()))) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    while(stk.size()) {
        postfix += stk.top();
        stk.pop();
    }
    cout << postfix;
    
    return 0;
}

//A+(B*C)*D*E+F   -->    ABC*D*E*+F+
//A*B+C -> (A*B)+C -> AB*C+
