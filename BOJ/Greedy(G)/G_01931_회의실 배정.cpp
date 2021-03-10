#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1931 회의실 배정

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    
    while(n--) {
        int st, ed;
        cin >> st >> ed;
        v.push_back({ed, st});
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0;
    int ed = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i].second < ed) continue;
        ed = v[i].first;
        ans++;
    }
    cout << ans;
    
    return 0;
}
