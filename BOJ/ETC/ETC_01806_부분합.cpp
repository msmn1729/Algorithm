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

//https://www.acmicpc.net/problem/1806 부분합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, s;
    int ar[100000] = {};
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    
    int sum = 0, st = 0, ed = 0, ans = 2e9;
    while(1) {
        if(sum < s) {
            if(ed == n) break;
            sum += ar[ed++];
        }
        else sum -= ar[st++];
        if(sum >= s) ans = min(ans, ed - st);
    }
    if(ans == 2e9) cout << 0;
    else cout << ans;
    
    return 0;
}
