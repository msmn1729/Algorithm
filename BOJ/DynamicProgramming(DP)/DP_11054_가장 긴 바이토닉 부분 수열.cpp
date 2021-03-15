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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/11054 가장 긴 바이토닉 부분 수열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int ar[1001] = {};
    int LIS[1001] = {};
    int r_LIS[1001] = {};
    int ans = 0;
    cin >> n;
    
    for(int i=1; i<=n; i++) cin >> ar[i];
    
    for(int i=1; i<=n; i++) {
        LIS[i] = 1;
        r_LIS[n-i+1] = 1;
        for(int j=1; j<i; j++) {
            if(ar[j] < ar[i]) LIS[i] = max(LIS[i], LIS[j] + 1);
            if(ar[n-j+1] < ar[n-i+1]) r_LIS[n-i+1] = max(r_LIS[n-i+1], r_LIS[n-j+1] + 1);
        }
    }
    
    for(int i=1; i<=n; i++) ans = max(ans, LIS[i] + r_LIS[i] - 1);
    
    cout << ans;
    
    return 0;
}
