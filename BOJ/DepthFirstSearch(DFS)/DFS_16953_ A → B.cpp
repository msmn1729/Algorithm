#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/16953 A → B

ll dfs(ll a, int b, int depth) {
    if(a > INF) return INF; //10억을 초과하면 10억 리턴
    if(a == b) return depth;
    return min(dfs(a*2, b, depth+1), dfs(a*10+1, b, depth+1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    ll ans = dfs(a, b, 1);
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
