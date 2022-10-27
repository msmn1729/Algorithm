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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    int ans = -2e9;
    
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        if(i<k) continue;
        ans = max(ans, v[i] - v[i-k]);
    }
    cout << ans;

    return 0;
}
