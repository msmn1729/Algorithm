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
    vector<int> v(n);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

    return 0;
}
