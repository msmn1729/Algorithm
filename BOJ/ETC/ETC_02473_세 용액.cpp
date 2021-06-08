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

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    ll min_sum = 4e9;
    ll ans1 = -1, ans2 = -1, ans3 = -1;
    
    for(int start=0; start<n; start++) {
        int left = start+1, right = n-1;
        while(left < right) {
            ll sum = v[start] + v[left] + v[right];
            if(min_sum > abs(sum)) {
                min_sum = abs(sum);
                ans1 = v[start];
                ans2 = v[left];
                ans3 = v[right];
            }
            if(sum < 0) left++;
            else right--;
        }
    }
    
    cout << ans1 << ' ' << ans2 << ' ' << ans3;
    
    return 0;
}
