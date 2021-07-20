#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/4368 별자리 만들기

int parent[101];

int find(int a) {
    if(parent[a] == -1) return a;
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
    
    int n;
    vector<pair<double, double>> pos;
    vector<tuple<double, int, int>> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        parent[i] = -1;
        string s1, s2;
        cin >> s1 >> s2;
        double x = stof(s1);
        double y = stof(s2);
        pos.push_back({x, y});
    }
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            double f = pos[i].first - pos[j].first;
            double s = pos[i].second - pos[j].second;
            v.push_back({sqrt(f*f + s*s), i, j});
        }
    }
    sort(v.begin(), v.end());
    
    double ans = 0;
    for(auto &[dist, st, ed] : v) {
        if(!merge(st, ed)) continue;
        ans += dist;
    }
    printf("%.2lf", ans);
//    cout << setprecision(2) << fixed << ans;
    
    return 0;
}
