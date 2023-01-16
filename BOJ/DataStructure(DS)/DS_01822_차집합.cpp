#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, in;
    cin >> a >> b;
    map<int, int> m;
    
    for(int i=0; i<a; i++) {
        cin >> in;
        m[in] = 1;
    }
    
    for(int i=0; i<b; i++) {
        cin >> in;
        if(m.find(in) != m.end()) m.erase(in);
    }
    
    cout << m.size() << '\n';
    
    for(auto it : m) cout << it.first << ' ';
    
    return 0;
}
