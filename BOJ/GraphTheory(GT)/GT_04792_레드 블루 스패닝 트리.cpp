#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/4792 레드 블루 스패닝 트리

struct info {
    char color;
    int st, ed;
};

int n, m, k;
int parent[1010];
vector<info> edges[2];

void init() {
    for(int i=0; i<2; i++) edges[i].clear();
    
    for(int i=0; i<m; i++) {
        char color;
        int st, ed;
        cin >> color >> st >> ed;
        edges[0].push_back({color, st, ed});
        edges[1].push_back({color, st, ed});
    }
}

int find(int a) {
    if(parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[a] = b;
    return true;
}

// MST 파란 간선의 개수 반환
int kruskal(int mode) {
    memset(parent, -1, sizeof(parent));
    int blue_cnt = 0, cnt = 0;
    
    for(auto &[color, st, ed] : edges[mode]) {
        if(!merge(st, ed)) continue;
        cnt++;
        if(color == 'B') blue_cnt++;
    }
    
    // MST 가능
    if(cnt == n-1) return blue_cnt;
    return -1; // MST 불가
}

bool red_cmp(info a, info b) {
    return a.color > b.color;
}

bool blue_cmp(info a, info b) {
    return a.color < b.color;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(1) {
        cin >> n >> m >> k;
        if(!n && !m && !k) break;
        init();
        // 빨간간선 우선 -> 파란간선 최소
        sort(edges[0].begin(), edges[0].end(), red_cmp);
        int min_blue = kruskal(0);
        // 파란간선 우선 -> 파란간선 최대
        sort(edges[1].begin(), edges[1].end(), blue_cmp);
        int max_blue = kruskal(1);
        
        // MST를 구성하는 파란간선의 최소개수 <= k <= 파란간선의 최대개수를 만족하면 1
        if(min_blue <= k && k <= max_blue) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
