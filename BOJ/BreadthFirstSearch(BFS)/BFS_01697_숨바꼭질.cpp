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

//https://www.acmicpc.net/problem/1697 숨바꼭질

using namespace std;
int dist[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, search;
    cin >> n >> search;
    fill(dist, dist+100001, -1);
    
    //BFS
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(dist[search] == -1)
    {
        int cur = q.front(); q.pop();
        for(int x: {cur-1, cur+1, cur*2})
        {
            if(x < 0 || x > 100000) continue;
            if(dist[x] > -1) continue;
            dist[x] = dist[cur] + 1;
            q.push(x);
        }
    }
    cout << dist[search];
    
    return 0;
}
