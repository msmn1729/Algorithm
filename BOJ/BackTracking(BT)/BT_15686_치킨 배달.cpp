#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/15686 치킨 배달

int n, m;
int vis[51];
int cnt, ans = 2e9;
vector<pii> chicken;
vector<pii> house;

// 최소 도시의 치킨거리를 반환
int AllDist(vector<pii>& v) {
    int ret = 0;
    // 집 최대 100, 치킨집 최대 13 -> 100*13 = 1300
    for(int i=0; i<house.size(); i++) {
        int x = house[i].first;
        int y = house[i].second;
        int mn = 2e9;
        // 한 집에서 제일 가까운 치킨거리 찾기
        for(int j=0; j<v.size(); j++) {
            int nx = v[j].first;
            int ny = v[j].second;
            mn = min(mn, (abs(x - nx) + abs(y - ny)));
        }
        ret += mn;
    }
    return ret;
}

void go(int start, int depth) {
    if(depth == m) {
        vector<pii> select_chicken;
        for(int i=0; i<chicken.size(); i++) {
            if(!vis[i]) continue;
            select_chicken.push_back(chicken[i]);
        }
        ans = min(ans, AllDist(select_chicken));
        return;
    }
    for(int i=start; i<chicken.size(); i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        go(i+1, depth+1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int a;
            cin >> a;
            if(a == 1) house.push_back({i, j});
            else if(a == 2) chicken.push_back({i, j});
        }
    }
    go(0, 0);
    cout << ans;

    return 0;
}
