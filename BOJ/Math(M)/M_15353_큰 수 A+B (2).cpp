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

//https://www.acmicpc.net/problem/15353 큰 수 A+B (2)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a, b, ans;
    cin >> a >> b;
    int sum = 0;
    while(a.size() || b.size() || sum)
    {
        if(a.size())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        ans.push_back(sum%10 + '0');
        sum /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
