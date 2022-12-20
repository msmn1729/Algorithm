#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> dist(n+1, -1);
    
    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        
        for(int i=1; i<=v[cur]; i++) {
            int nxt = cur + i;
            if(nxt < 1 || nxt > n) continue;
            if(dist[nxt] > -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    cout << dist[n];
    
    return 0;
}
