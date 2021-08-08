#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/9466 텀 프로젝트

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        int ar[101010] = {};
        int indegree[101010] = {};
        cin >> n;
        
        for(int i=1; i<=n; i++) {
            cin >> ar[i];
            indegree[ar[i]]++;
        }
        
        // 진입차수 0인 것들 큐에 넣기
        queue<int> q;
        int ans = 0;
        
        for(int i=1; i<=n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                ans++;
            }
        }
        
        while(q.size()) {
            int cur = q.front(); q.pop();
            int nxt = ar[cur];
            indegree[nxt]--;
            if(indegree[nxt] == 0) {
                q.push(nxt);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
