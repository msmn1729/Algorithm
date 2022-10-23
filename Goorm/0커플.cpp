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

    int n;
    cin >> n;
    map<int, int> m;
    for(int i=0; i<n; i++) {
        int in;
        cin >> in;
        
        if(m[abs(in)]) {
            m.erase(abs(in));
            continue;
        }
        if(in < 0) m[abs(in)] = -1;
        else m[abs(in)] = 1;
    }
    
    int ans = 0;
    for(auto &it : m) {
        ans += it.first * it.second;
    }
    cout << ans;

    return 0;
}
