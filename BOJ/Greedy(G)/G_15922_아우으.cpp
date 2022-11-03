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
    vector<pair<int, int> > v(n);
    
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    
    int left = v[0].first;
    int right = v[0].second;
    int ans = 0;
    
    for(int i=1; i<n; i++) {
        // 선분이 끊기는 경우
        if(right < v[i].first) {
            ans += right - left;
            left = v[i].first;
            right = v[i].second;
        }
        // 선분이 겹치는 경우
        else if(v[i].first <= right && right <= v[i].second) {
            right = v[i].second;
        }
    }
    ans += right - left;
    
    cout << ans;
    
    return 0;
}
