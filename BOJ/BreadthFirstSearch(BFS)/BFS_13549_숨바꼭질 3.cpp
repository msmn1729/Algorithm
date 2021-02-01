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
#define INF 2e9

using namespace std;

//https://www.acmicpc.net/problem/13549 숨바꼭질 3

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dist[100001] = {};
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    q.push(n);
    dist[n] = 1;
    
    while(q.size()) {
        int cur = q.front(); q.pop();
        for(int nxt: {cur*2, cur-1, cur+1}) {
            if(nxt < 0 || nxt > 1e5) continue;
            if(dist[nxt]) continue;
            dist[nxt] = dist[cur];
            if(cur*2 != nxt) dist[nxt]++;
            q.push(nxt);
        }
    }
    cout << dist[k]-1;
    
    return 0;
}
