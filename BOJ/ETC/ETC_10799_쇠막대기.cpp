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

//https://www.acmicpc.net/problem/10799 쇠막대기
//생각해봐야하는 문제
//구현은 어렵지 않음

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    stack<char> stk;

    cin >> s;
    int ans = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            if(s[i+1] == ')') //레이저
            {
                ans += stk.size();
                i++;
            }
            else stk.push(s[i]);
        }
        else
        {
            stk.pop();
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}
