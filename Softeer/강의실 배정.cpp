#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    vector<pair<int, int> > v;
    cin >> n;
    
    while(n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int ans = 1;
    int ed = v[0].second;
    for(int i=1; i<v.size(); i++) {
        int st = v[i].first;
        if(ed <= st) {
            ans++;
            ed = v[i].second;
        }
    }
    cout << ans;

    return 0;
}
