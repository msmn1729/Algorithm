#include <bits/stdc++.h>
#define ll long long
using namespace std;

string n;
int k, ans;
int dp[1000001][11];

int dfs(string num, int cnt) {
    if(k == cnt) return stoi(num);
    int &ret = dp[stoi(num)][cnt];
    if(ret != -1) return ret;
    
    for(int i=0; i<n.size(); i++) {
        for(int j=i+1; j<n.size(); j++) {
            if(i == 0 && num[j] == '0') continue;
            swap(num[i], num[j]);
            ret = max(ret, dfs(num, cnt + 1));
            swap(num[i], num[j]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << dfs(n, 0);
    return 0;
}
