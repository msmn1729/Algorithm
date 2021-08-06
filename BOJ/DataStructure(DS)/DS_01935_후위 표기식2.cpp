#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1935 후위 표기식2

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    int alpa[30] = {};
    string s; cin >> s;
    
    for(int i=0; i<n; i++) cin >> alpa[i];
    
    stack<double> stk;
    for(int i=0; i<s.size(); i++) {
        if(isalpha(s[i])) {
            int num = alpa[s[i] - 'A'];
            stk.push(num);
        }
        else {
            if(stk.empty()) continue;
            double b = stk.top(); stk.pop();
            if(stk.empty()) continue;
            double a = stk.top(); stk.pop();
            
            if(s[i] == '+') stk.push(a + b);
            else if(s[i] == '-') stk.push(a - b);
            else if(s[i] == '*') stk.push(a * b);
            else if(s[i] == '/') stk.push(a / b);
        }
    }
    cout.precision(2);
    cout << fixed << stk.top();
    
    return 0;
}
