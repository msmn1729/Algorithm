#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    
    for(int i=1; i<=k; i++) {
        int n;
        cin >> n;
        
        vector<int> v(n);
        for(int j=0; j<n; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        cout << "Class " << i << '\n';
        cout << "Max " << v.back() << ", ";
        cout << "Min " << v.front() << ", ";
        
        int mx = 0;
        for(int j=0; j<n-1; j++) {
            mx = max(mx, v[j+1] - v[j]);
        }
        cout << "Largest gap " << mx << '\n';
    }
    
    return 0;
}
