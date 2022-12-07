#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> v(5);
    for(int i=0; i<v.size(); i++) {
        cin >> v[i];
    }
    
    int ans = 2e9;
    for(int i=1; i<=1000000; i++) {
        int cnt = 0;
        for(int j=0; j<v.size(); j++) {
            if(i % v[j] == 0) cnt++;
        }
        if(cnt >= 3) ans = min(ans, i);
    }
    cout << ans;
    
    return 0;
}

