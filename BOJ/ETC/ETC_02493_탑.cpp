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

//https://www.acmicpc.net/problem/2493 탑

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, in;
    stack<pair<int, int> > stk;
    
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> in;
        while(stk.size() && stk.top().second < in)
        {
            stk.pop();
        }
        if(stk.empty()) cout << 0 << ' ';
        else cout << stk.top().first << ' ';
        stk.push({i, in});
    }
    
    return 0;
}
