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
    string s2 = s.substr(s.length() / 2);
    s = s.substr(0, s.length() / 2);
    
    int sum = 0, sum2 = 0;
    for(int i=0; i<s.length(); i++) {
        sum += s[i] - '0';
        sum2 += s2[i] - '0';
    }
    
    if(sum == sum2) cout << "LUCKY";
    else cout << "READY";
    
    return 0;
}
