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

    vector<int> v(4);
    for(int i=0; i<v.size(); i++) {
        cin >> v[i];
    }
    
    int ans = -1;
    sort(v.begin(), v.end());
    ans = abs(v[0] - v[3]) + abs(v[1] - v[2]);
    
    cout << ans;

    return 0;
}
