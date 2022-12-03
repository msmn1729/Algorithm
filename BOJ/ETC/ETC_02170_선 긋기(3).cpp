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
    
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    
    int prevSt = v[0].first, prevEd = v[0].second;
    int ans = 0;
    
    for(int i=1; i<n; i++) {
        int st = v[i].first;
        int ed = v[i].second;
        
        // 연속이 끊어지는 경우
        if(prevEd < st) {
            ans += (prevEd - prevSt);
            prevSt = st;
        }
        // 연장되는 경우 or 이전 선분안에 포함되는 경우(항상 연장됨을 의미하지 않음)
        prevEd = max(prevEd, ed);
    }
    ans += (prevEd - prevSt);
    cout << ans;
    
    return 0;
}
