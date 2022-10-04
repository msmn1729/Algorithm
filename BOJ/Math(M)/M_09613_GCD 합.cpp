#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

int GCD(int x, int y) {
    if(y == 0) return x;
    return GCD(y, x % y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j=0; j<n; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end(), greater<>());
        ll sum = 0;
        for(int j=0; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                sum += GCD(v[j], v[k]);
            }
        }
        if(v.size() == 1) cout << 1 << '\n';
        else cout << sum << '\n';
    }
    
    return 0;
}
