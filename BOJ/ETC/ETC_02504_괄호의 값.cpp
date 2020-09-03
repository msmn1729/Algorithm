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

using namespace std;

//https://www.acmicpc.net/problem/2504 괄호의 값
//쉽지 않은 문제

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    stack<char> stk;

    cin >> s;
    int ans = 0;
    bool isValid = true;
    int tmp = 1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            tmp *= 2;
            stk.push(s[i]);
        }
        else if(s[i] == '[')
        {
            tmp *= 3;
            stk.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(stk.empty() || stk.top() != '(')
            {
                isValid = false;
                break;
            }
            else if(s[i-1] == '(') ans += tmp;
            tmp /= 2; //필수
            stk.pop();
        }
        else if(s[i] == ']')
        {
            if(stk.empty() || stk.top() != '[')
            {
                isValid = false;
                break;
            }
            else if(s[i-1] == '[') ans += tmp;
            tmp /= 3; //필수
            stk.pop();
        }
    }
    if(stk.size()) isValid = false;
    if(isValid) cout << ans;
    else cout << 0;
    
    return 0;
}
