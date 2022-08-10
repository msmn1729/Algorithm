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

int main() {
    int n, x;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    cin >> x;
    
    int ans = 0;
    sort(v.begin(), v.end());
    
    int st = 0, ed = n-1;
    while(st < ed) {
        int sum = v[st] + v[ed];
        if(sum == x) {
            ans++;
            ed--;
        }
        else if(sum < x) {
            st++;
        }
        else {
            ed--;
        }
    }
    cout << ans;
    
    return 0;
}
