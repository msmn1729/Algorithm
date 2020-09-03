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

//https://www.acmicpc.net/problem/4949 균형잡힌 세상
//원트

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    while(1)
    {
        getline(cin, s);
        if(s == ".") break; //종료조건
        stack<char> stk;
        int flag = 1;
        for(auto c : s)
        {
            if(c == '(' || c == '[') stk.push(c);
            else if(c == ')')
            {
                if(stk.empty() || stk.top() != '(')
                {
                    flag = 0;
                    break;
                }
                stk.pop();
            }
            else if(c == ']')
            {
                if(stk.empty() || stk.top() != '[')
                {
                    flag = 0;
                    break;
                }
                stk.pop();
            }
        }
        if(flag && stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}
