#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;
    ll sqrtNum = floor(sqrt(n));
    
    if(sqrtNum * sqrtNum < n) cout << sqrtNum + 1;
    else cout << sqrtNum;

    return 0;
}


