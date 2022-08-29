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
    
    int k, n, m;
    cin >> k >> n >> m;
    int ans = (k * n) - m;
    if(ans < 0) ans = 0;
    cout << ans;
    
    return 0;
}
