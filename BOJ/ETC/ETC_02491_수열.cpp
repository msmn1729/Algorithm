#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int ar[100001] = {};
    cin >> n;
    int ans = 0;
    int increaseLen = 1, decreaseLen = 1;
    int len1 = 1, len2 = 1;
    
    for(int i=0; i<n; i++) {
        cin >> ar[i];
        if(i == 0) continue;
        if(ar[i-1] <= ar[i]) {
            len1++;
        }
        else {
            len1 = 1;
        }
        increaseLen = max(increaseLen, len1);
        
        if(ar[i-1] >= ar[i]) {
            len2++;
        }
        else {
            len2 = 1;
        }
        decreaseLen = max(decreaseLen, len2);
    }
    ans = max(increaseLen, decreaseLen);
    cout << ans;
    
    return 0;
}

