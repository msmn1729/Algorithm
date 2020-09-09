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

//https://www.acmicpc.net/problem/5567 결혼식

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    vector<int> v[501];
    int dist[501] = {};

    cin >> n >> m;
    //양방향 그래프
    while(m--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    //BFS
    queue<int> q;
    q.push(1); //시작 정점은 1
    dist[1] = 1; //시작 정점도 방문처리

    while(q.size())
    {
        int cur = q.front(); q.pop();

        for(int i=0; i<v[cur].size(); i++)
        {
            int next = v[cur][i];
            if(dist[next]) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    int ans = 0;
    for(int i=2; i<=n; i++) //나를 제외한 전체 동기 중에
    {
        if(2 <= dist[i] && dist[i] <= 3) ans++;
    }
    cout << ans;

    return 0;
}
