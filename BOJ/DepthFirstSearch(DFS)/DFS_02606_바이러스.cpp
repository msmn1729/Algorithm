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

//https://www.acmicpc.net/problem/2606 바이러스

int n, m, st, ed, ans, cnt;
int board[101][101];
int visit[101];

void dfs(int start)
{
    visit[start] = 1;
    ans++;
    for(int i=1; i<=n; i++) //정점 개수만큼
    {
        if(visit[i] == 1 || board[start][i] == 0) continue;
        dfs(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> st >> ed;
        board[st][ed] = board[ed][st] = 1;
    }
    dfs(1);
    cout << ans-1;
    
    return 0;
}
