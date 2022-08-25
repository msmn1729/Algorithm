#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#define ll long long
using namespace std;

struct info {
    int pos, state;
};

bool cmp(info a, info b) {
    if(a.pos == b.pos) return a.state < b.state;
    return a.pos < b.pos;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<info> v;
    
    for(int i=0; i<n; i++) {
        int pos;
        cin >> pos;
        v.push_back({pos, 1});
        cin >> pos;
        v.push_back({pos, 0});
    }
    sort(v.begin(), v.end(), cmp);
    
    int ans = 1, cnt = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i].state) cnt++;
        else cnt--;
        ans = max(ans, cnt);
    }
    cout << ans;
    
    return 0;
}
