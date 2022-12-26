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
    vector<int> maxV;
    int mx = 0;
    
    for(int i=1; i<=n; i++) {
        vector<int> v = {n, i};
        
        for(int j=2; ; j++) {
            int nxt = v[j-2] - v[j-1];
            if(nxt < 0) break;
            v.push_back(nxt);
        }
        
        if(mx < v.size()) {
            mx = (int)v.size();
            maxV = v;
        }
    }
    
    cout << mx << '\n';
    for(int it : maxV) {
        cout << it << ' ';
    }
    
    return 0;
}
