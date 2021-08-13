#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/13410 거꾸로 구구단

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i=1; i<=k; i++) {
        string s = to_string(n * i);
        reverse(s.begin(), s.end());
        int num = stoi(s);
        ans = max(ans, num);
    }
    cout << ans;
    
    return 0;
}
