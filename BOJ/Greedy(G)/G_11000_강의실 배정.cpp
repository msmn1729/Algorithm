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

//https://www.acmicpc.net/problem/11000 강의실 배정

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    cin >> n;
    vector<pair<int, int> > v;

    for(i=0; i<n; i++)
    {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    pq.push(v.front().second);

    for(i=1; i<n; i++)
    {
        if(v[i].first >= pq.top()) //이어서 쓸 수 있을 때
        {
            pq.pop();
            pq.push(v[i].second);
        }
        else
        {
            pq.push(v[i].second);
        }
    }
    cout << pq.size();
    
    return 0;
}
