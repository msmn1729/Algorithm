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

//https://www.acmicpc.net/problem/6198 옥상 정원 꾸미기

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long ans = 0;
    int n, h;
    stack<int> s;
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> h;
        while(s.size() && s.top() <= h)
        {
            s.pop();
        }
        s.push(h);
        ans += s.size() - 1;
    }
    cout << ans;
    return 0;
}
