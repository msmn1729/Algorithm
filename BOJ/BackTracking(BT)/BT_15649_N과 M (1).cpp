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

using namespace std;

//https://www.acmicpc.net/problem/15649 N과 M (1)

int combi[10], visit[10];
int n, m;

void dfs(int depth)
{
    if(depth == m)
    {
        for(int i=0; i<m; i++)
        {
            cout << combi[i] << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=n; i++)
    {
        if(visit[i]) continue;
        visit[i] = 1;
        combi[depth] = i;
        dfs(depth+1);
        visit[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    dfs(0);
    
    return 0;
}
