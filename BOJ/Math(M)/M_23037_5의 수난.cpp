#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        int num = s[i] - '0';
        int mul = 1;
        
        for(int j=0; j<5; j++) {
            mul *= num;
        }
        ans += mul;
    }
    cout << ans;
    
    return 0;
}
