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

//https://www.acmicpc.net/problem/1629 곱셈

ll a, b, c;

ll go(ll a, ll b, ll c) {
    if(b == 0) return 1;
    ll ret = go(a, b/2, c);
    ret = ret * ret % c;
    if(b%2 == 0) return ret;
    return (ret * a) % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> a >> b >> c;
    cout << go(a, b, c);
    
    return 0;
}
