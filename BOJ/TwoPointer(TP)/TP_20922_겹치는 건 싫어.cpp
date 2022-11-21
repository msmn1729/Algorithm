#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    int st = 0, ed = 0;
    int numChk[100001] = {};
    int ans = 1;
    
    while(st <= ed && ed < n) {
        int stNum = v[st];
        int edNum = v[ed];
        
        if(numChk[edNum] < k) {
            numChk[edNum]++;
            ed++;
            ans = max(ans, ed - st);
        }
        else {
            numChk[stNum]--;
            st++;
        }
    }
    cout << ans;
    
    return 0;
}
