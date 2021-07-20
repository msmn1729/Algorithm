#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14621 나만 안되는 연애

int parent[1010];
int type[1010];

int find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        parent[i] = i;
        char c;
        cin >> c;
        if(c == 'M') type[i] = 1;
    }
    
    vector<tuple<int, int, int>> v;
    for(int i=0; i<m; i++) {
        ll st, ed, cost;
        cin >> st >> ed >> cost;
        if(type[st] == type[ed]) continue;
        v.push_back({cost, st, ed});
    }
    sort(v.begin(), v.end());
    
    int ans = 0, cnt = 0;
    for(auto &[cost, st, ed] : v) {
        if(merge(st, ed)) {
            ans += cost;
            cnt++;
        }
    }
    
    // 경로가 없으면 -1 출력
    if(cnt < n-1) ans = -1;
    cout << ans;
    
    return 0;
}
