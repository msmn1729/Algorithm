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
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    int left = 0, right = n-1;
    int min_dif = 2e9;
    int ans1 = -1, ans2 = -1;
    
    while(left < right) {
        int dif = abs(v[left] + v[right]);
        if(min_dif > dif) {
            min_dif = dif;
            ans1 = v[left];
            ans2 = v[right];
        }
        if(v[left] + v[right] < 0) left++;
        else right--;
    }
    cout << ans1 << ' ' << ans2;
    
    return 0;
}

