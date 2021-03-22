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

//https://www.acmicpc.net/problem/2217 로프

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int ar[100001] = {};
    cin >> n;
    for(int i=0; i<n; i++) cin >> ar[i];
    sort(ar, ar+n);
    
    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans, ar[i] * (n-i));
    cout << ans;
    
    return 0;
}
