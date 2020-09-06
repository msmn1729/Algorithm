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

//https://www.acmicpc.net/problem/4889 안정적인 문자열

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a;
    int i, ans;
    for(i=1; ; i++)
    {
        ans = 0;
        cin >> a;
        if(a[0] == '-') break;
        
        stack<char> s;
        for(char c : a)
        {
            if(c == '}' && s.size() && s.top() == '{')
                s.pop();
            else
                s.push(c);
        }
        
        char left, right;
        while(s.size())
        {
            left = s.top(); s.pop();
            right = s.top(); s.pop();
            if(left == right) ans++;
            else ans += 2;
        }
        cout << i << ". " << ans << '\n';
    }
    return 0;
}
