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
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/12851 숨바꼭질 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    int dist[100001] = {};
    cin >> n >> k;
    
    queue<int> q;
    q.push(n);
    dist[n] = 1;
    
    int cnt = 0;
    while(q.size()) {
        int x = q.front();
        q.pop();
        if(x == k) cnt++;
        for(int nx: {x-1, x+1, x*2}) {
            if(nx < 0 || nx > 1e5) continue;
            if(dist[nx] && (dist[nx] != dist[x]+1)) continue; //방문했던 곳이면서 최단거리가 아닌경우 패스
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }
    cout << dist[k]-1 << '\n' << cnt;
    
    return 0;
}

