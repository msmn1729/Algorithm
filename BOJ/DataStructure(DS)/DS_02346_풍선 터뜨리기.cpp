#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2346 풍선 터뜨리기

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    deque<pii> dq;
    int n; cin >> n;
    
    for(int i=1; i<=n; i++) {
        int a; cin >> a;
        dq.push_back({i, a});
    }
    
    int val = dq.front().second;
    cout << dq.front().first << ' ';
    dq.pop_front();
    
    while(dq.size()) {
        if(val > 0) {
            for(int i=0; i<val; i++) {
                auto prev = dq.front();
                dq.pop_front();
                dq.push_back(prev);
            }
            val = dq.back().second;
            cout << dq.back().first << ' ';
            dq.pop_back();
        }
        else {
            val *= -1;
            for(int i=0; i<val; i++) {
                auto prev = dq.back();
                dq.pop_back();
                dq.push_front(prev);
            }
            val = dq.front().second;
            cout << dq.front().first << ' ';
            dq.pop_front();
        }
    }
    
    return 0;
}
