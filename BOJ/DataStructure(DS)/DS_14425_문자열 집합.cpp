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
#define INF 1e9
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<string, int> info;
    vector<string> v(n);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    for(int i=0; i<m; i++) {
        string s;
        cin >> s;
        info[s]++;
    }
    
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += info[v[i]];
    }
    cout << ans;
    
    return 0;
}
