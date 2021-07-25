#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1343 폴리오미노

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s, ans = "";
    cin >> s;
    
    ans = regex_replace(s, regex("XXXX"), "AAAA");
    ans = regex_replace(ans, regex("XX"), "BB");
    if(ans.find("X") == string::npos) cout << ans;
    else cout << -1;
    
    return 0;
}
