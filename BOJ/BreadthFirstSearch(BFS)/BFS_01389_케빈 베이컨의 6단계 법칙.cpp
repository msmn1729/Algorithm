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
#include <unordered_map>
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/1389 케빈 베이컨의 6단계 법칙

int ar[101][101];
int n, m;
int visit[101];

void init() {
    for(int i=1; i<=n; i++) visit[i] = 0;
}

void bfs(int start) {
    visit[start] = 1;
    queue<int> q;
    q.push(start);
    
    while(q.size()) {
        start = q.front();
        q.pop();
        
        for(int i=1; i<=n; i++) {
            if(visit[i] || !ar[start][i]) continue; //방문했었거나 연결이 안된 곳 패스
            visit[i] = visit[start]+1;
            q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ar[a][b] = ar[b][a] = 1;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
    for(int i=1; i<=n; i++) {
        init();
        bfs(i);
        
        int sum = 0;
        for(int j=1; j<=n; j++) {
            if(i == j) continue;
            sum += visit[j]-1;
        }
        pq.push({sum, i});
    }
    cout << pq.top().second;
    
    return 0;
}
