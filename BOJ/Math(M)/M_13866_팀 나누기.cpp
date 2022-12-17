#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> v(4);
    for(int i=0; i<4; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << abs(v[0] + v[3] - (v[1] + v[2]));
    
    return 0;
}
