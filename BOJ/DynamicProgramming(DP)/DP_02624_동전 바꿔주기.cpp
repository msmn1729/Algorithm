#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#define ll long long
using namespace std;

struct info {
    int price, cnt;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dp[10001] = {1};
    int t, k;
    cin >> t >> k;
    vector<info> v(k+1);
    
    for(int i=1; i<=k; i++) cin >> v[i].price >> v[i].cnt;
    
    for(int i=1; i<=k; i++) {
        int price = v[i].price;
        int cnt = v[i].cnt;
        
        for(int j=t; j>0; j--) {
            for(int n=1; n<=cnt; n++) {
                if(j - price * n < 0) continue;
                dp[j] += dp[j - price * n];
            }
        }
    }
    cout << dp[t];
    
    return 0;
}
