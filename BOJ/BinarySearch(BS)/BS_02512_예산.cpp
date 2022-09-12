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
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cin >> m;
    sort(v.begin(), v.end());
    
    int left = 0, right = v.back();
    int ans = 0;
    
    while(left <= right) {
        int sum = 0;
        int mid = (left + right) / 2;
        
        for(int i=0; i<n; i++) {
            sum += min(v[i], mid);
        }
        
        if(sum <= m) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;
    
    return 0;
}
