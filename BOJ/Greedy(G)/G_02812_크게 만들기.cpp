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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/2812 크게 만들기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    string s, ans;
    cin >> n >> k >> s;
    
    for(int i=0; i<n; i++)
    {
        while(k && ans.size() && ans.back() < s[i])
        {
            ans.pop_back();
            k--;
        }
        ans += s[i];
    }
    while(k--) ans.pop_back();
    cout << ans;
    
    return 0;
}
