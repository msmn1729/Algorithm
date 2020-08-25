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

//https://www.acmicpc.net/problem/15665 N과 M (11)

int combi[10], visit[10001], num[10];
int n, m;
set< vector<int> > s;

void dfs(int start, int depth)
{
    if(depth == m)
    {
        vector<int> tmp;
        for(int i=0; i<m; i++)
        {
            tmp.push_back(combi[i]);
        }
        s.insert(tmp);
        return;
    }
    for(int i=0; i<n; i++)
    {
//        if(visit[i]) continue;
//        visit[i] = 1;
        combi[depth] = num[i];
        dfs(i, depth+1);
//        visit[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> num[i];
    }
    sort(num, num+n);
    dfs(0, 0);
    
    for(auto it : s)
    {
        for(auto it2 : it)
        {
            cout << it2 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
