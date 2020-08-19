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
#include <cstdlib>
#include <cmath>

using namespace std;

//https://www.acmicpc.net/problem/1260 DFS와 BFS 실버2

int ary[1001][1001];
int visit[1001]; //방문체크
int n, m, start;

void DFS(int start) //재귀로 구현
{
    cout << start << ' '; //첫 정점 번호 출력
    visit[start] = 1; //방문체크
    for(int i=1; i<=n; i++) //정점의 갯수만큼 반복
    {
        if(visit[i] == 1 || ary[start][i] == 0) continue; //방문을 했거나 인접행렬에
        DFS(i);
    }
}

void BFS(int start) //큐로 구현
{
    queue<int> q;
    q.push(start);
    visit[start] = 1; //방문체크
    while(!q.empty())
    {
        start = q.front();
        cout << start << ' ';
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(visit[i] == 1 || ary[start][i] == 0) continue;
            q.push(i);
            visit[i] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, a, b;
    cin >> n >> m >> start;
    
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        ary[a][b] = ary[b][a] = 1; //인접행렬
    }
    DFS(start);

    memset(visit, 0, sizeof(visit));
    cout << '\n';
    BFS(start);
    
    return 0;
}
