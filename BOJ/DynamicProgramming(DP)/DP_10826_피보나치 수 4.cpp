#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

string sum(string a, string b) {
    string ret = "";
    int sum = 0;
    
    while(a.size() || b.size() || sum) {
        if(a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret += to_string(sum % 10);
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    string dp[10001] = {"0", "1"};
    cin >> n;

    for(int i=2; i<=n; i++) {
        dp[i] = sum(dp[i-1], dp[i-2]);
    }
    cout << dp[n];
    
    return 0;
}

