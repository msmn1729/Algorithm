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
    vector<pair<int, int> > v(n);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end());
    
    int prevLeft = v[0].first;
    int prevRight = v[0].second;
    int ans = 0;
    
    for(int i=1; i<n; i++) {
        int curLeft = v[i].first;
        int curRight = v[i].second;
        
        // 1. 이전 선분 안에 포함되는 경우 패스 ex) 1~5, 2~5
        if(prevRight >= curRight) continue;
        
        // 2. 연속된 선분이 끊어지는 경우
        if(prevRight < curLeft) {
            ans += prevRight - prevLeft;
            prevLeft = curLeft;
            prevRight = curRight;
        }
        
        // 3. 선분이 이어지는 경우
        else {
            prevRight = curRight;
        }
    }
    ans += prevRight - prevLeft;
    
    cout << ans;
    
    return 0;
}
