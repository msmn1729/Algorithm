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

//https://www.acmicpc.net/problem/1931 회의실배정

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, st, ed;
    vector<pair<int, int> > v;
    cin >> n;
    int ans = 1;
    while(n--)
    {
        cin >> st >> ed;
        v.push_back({ed, st});
    }
    sort(v.begin(), v.end());
    
    int end = v[0].first;
    for(i=1; i<v.size(); i++)
    {
        if(end > v[i].second) continue;
        ans++;
        end = v[i].first;
    }
    cout << ans;
    
    return 0;
}
