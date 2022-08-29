#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    do {
        int sum = 0;
        for(int i=0; i<n-1; i++) {
            sum += abs(v[i] - v[i+1]);
        }
        ans = max(ans, sum);
    } while(next_permutation(v.begin(), v.end()));
    
    cout << ans;
    
    return 0;
}
