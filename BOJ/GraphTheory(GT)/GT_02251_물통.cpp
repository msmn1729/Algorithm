#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2251 물통

queue<pii> q;
int visited[202][202] = {}; // a, b 방문처리

void pour(int nxt_a, int nxt_b) {
    if(visited[nxt_a][nxt_b]) return;
    visited[nxt_a][nxt_b] = 1;
    q.push({nxt_a, nxt_b});
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    q.push({0, 0});
    visited[0][0] = 1;

    vector<int> ans;
    while(!q.empty()) {
        int cur_a = q.front().first;
        int cur_b = q.front().second; q.pop();
        int cur_c = c - cur_a - cur_b; // 총량에서 a, b를 빼줌
        
        // 정답 벡터에 추가
        if(cur_a == 0) ans.push_back(cur_c);
        
        // 6가지 경우의 수
        // 1. a -> b
        int water = min(cur_a, b - cur_b);
        pour(cur_a - water, cur_b + water);
        
        // 2. a -> c
        water = min(cur_a, c - cur_c);
        pour(cur_a - water, cur_b);
        
        // 3. b -> a
        water = min(cur_b, a - cur_a);
        pour(cur_a + water, cur_b - water);
        
        // 4. b -> c
        water = min(cur_b, c - cur_c);
        pour(cur_a, cur_b - water);
        
        // 5. c -> a
        water = min(cur_c, a - cur_a);
        pour(cur_a + water, cur_b);
        
        // 6. c -> b
        water = min(cur_c, b - cur_b);
        pour(cur_a, cur_b + water);
    }
    sort(ans.begin(), ans.end());
    for(int &it : ans) cout << it << ' ';
    
    return 0;
}
