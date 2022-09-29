#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    stack<char> stk;
    int ans = 0, mul = 1;
    int flag = 0;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            stk.push(s[i]);
            mul *= 2;
        }
        else if(s[i] == '[') {
            stk.push(s[i]);
            mul *= 3;
        }
        
        if(stk.empty()) {
            flag = 1;
            break;
        }
        
        if(i > 0 && s[i] == ')') {
            if(s[i-1] == '(') ans += mul;
            mul /= 2;
            if(stk.top() == '(') stk.pop();
            else {
                flag = 1;
                break;
            }
        }
        else if(i > 0 && s[i] == ']') {
            if(s[i-1] == '[') ans += mul;
            mul /= 3;
            if(stk.top() == '[') stk.pop();
            else {
                flag = 1;
                break;
            }
        }
    }
    
    if(stk.size()) flag = 1;
    if(flag) cout << 0;
    else cout << ans;
    
    return 0;
}
