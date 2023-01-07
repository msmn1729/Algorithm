#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    while(n--) {
        string s;
        cin >> s;
        if(6 <= s.size() && s.size() <= 9) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}
