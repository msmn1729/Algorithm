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

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, mx = 0;
    map<ll, int> m;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        ll num;
        cin >> num;
        m[num]++;
        mx = max(mx, m[num]);
    }
    
    for(auto it : m) {
        if(it.second == mx) {
            cout << it.first;
            break;
        }
    }
    
    return 0;
}
