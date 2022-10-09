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

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        
        ll stIdx = lower_bound(v.begin(), v.end(), st) - v.begin();
        ll edIdx = upper_bound(v.begin(), v.end(), ed) - v.begin();
        cout << edIdx - stIdx << '\n';;
    }
    
    return 0;
}
