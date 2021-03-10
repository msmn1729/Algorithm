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

//https://www.acmicpc.net/problem/11047 동전 0

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    int ar[11] = {};
    
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> ar[i];
    
    int ans = 0;
    for(int i=n-1; i>=0; i--) {
        ans += k / ar[i];
        k %= ar[i];
    }
    cout << ans;
    
    return 0;
}
