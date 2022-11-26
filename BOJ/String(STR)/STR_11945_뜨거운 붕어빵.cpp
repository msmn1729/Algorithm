#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c;
    cin >> r >> c;
    string s;
    
    while(r--) {
        cin >> s;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
    
    return 0;
}
