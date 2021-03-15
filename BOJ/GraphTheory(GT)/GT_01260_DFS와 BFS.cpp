#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1260 DFS와 BFS

int n, m, start;
int ar[1001][1001];
int visit[1001];

void DFS(int start) {
    cout << start << ' ';
    visit[start] = 1;
    for(int i=1; i<=n; i++) {
        if(visit[i]) continue;
        if(ar[start][i]) DFS(i);
    }
}

void BFS(int start) {
    queue<int> q;
    visit[start] = 1;
    q.push(start);
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int i=1; i<=n; i++) {
            if(visit[i]) continue;
            if(ar[cur][i]) {
                visit[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> start;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ar[a][b] = ar[b][a] = 1;
    }
    DFS(start);
    memset(visit, 0, sizeof(visit));
    cout << '\n';
    BFS(start);
    
    return 0;
}
