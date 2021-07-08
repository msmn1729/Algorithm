#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1039 교환

int n, k;

int conv(int n, int l, int r) {
    string s = to_string(n);
    swap(s[l], s[r]);
    if(s[0] == '0') return -1; // 예외처리
    return stoi(s);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    int len = (int)to_string(n).size(); // 숫자의 자릿수
    
    // k번 반복
    for(int i=1; i<=k; i++) {
        unordered_map<int, int> um;
        while(q.size()) {
            int cur = q.front(); q.pop();
            for(int l=0; l<len; l++) {
                for(int r=l+1; r<len; r++) {
                    int nxt = conv(cur, l, r);
                    if(nxt == -1) continue;
                    if(um[nxt]) continue;
                    um[nxt] = 1;
                }
            }
        }
        // 횟수에 맞게 중복제거해서 큐에 삽입
        for(auto it : um) q.push(it.first);
    }
    
    int ans = -1; // 예외는 -1
    while(q.size()) {
        ans = max(ans, q.front());
        q.pop();
    }
    cout << ans;

    return 0;
}
