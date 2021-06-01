#include <unordered_map>
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

int go(ll idx) {
    if(idx <= 1) return (int)idx;
    if(idx%2 == 0) return go(idx/2);
    else return !go(idx/2);
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    ll k;
    cin >> k;
    cout << go(k-1);
    
    return 0;
}

