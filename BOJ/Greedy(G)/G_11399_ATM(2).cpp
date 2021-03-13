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

//https://www.acmicpc.net/problem/11399 ATM

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    int ans = 0;
    for(int i=0; i<n; i++) ans += v[i] * (n-i);
    cout << ans;
    
    return 0;
}
