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

//https://www.acmicpc.net/problem/15651 N과 M (3)
//중복 허용하는 형태는 가장 심플하다!

int combi[10];
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
        return;
    }
    for(int i=1; i<=n; i++)
    {
        combi[depth] = i;
        dfs(depth+1);
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
