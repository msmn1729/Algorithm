#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14391 종이 조각

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ar[5][5] = {};
    int r, c;
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        string s; cin >> s;
        for(int j=0; j<s.size(); j++) ar[i][j] = s[j] - '0';
    }
    
    int mul = r * c;
    int limit = (1 << mul); // 최대 2^16
    int ans = 0;
    
    // 가로 : 0, 세로 : 1
    for(int bit=0; bit<limit; bit++) {
        // 가로
        int sum = 0;
        for(int i=0; i<r; i++) {
            
            int cur = 0;
            for(int j=0; j<c; j++) {
                int idx = i * c + j;
                if((bit & (1 << idx)) == 0) {
                    cur = cur * 10 + ar[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        
        // 세로
        for(int j=0; j<c; j++) {
            
            int cur = 0;
            for(int i=0; i<r; i++) {
                int idx = i * c + j;
                if((bit & (1 << idx)) != 0) {
                    cur = cur * 10 + ar[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }
    cout << ans;
    
    return 0;
}
