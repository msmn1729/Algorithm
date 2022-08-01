#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

int n;
int ar[101], combi[101], oper[4];
int mn = 2e9, mx = -2e9;

void go(int depth, int ans, int add, int sub, int mul, int div) {
    if(depth == n) {
        mn = min(mn, ans);
        mx = max(mx, ans);
        return;
    }
    if(add) go(depth + 1, ans + ar[depth], add - 1, sub, mul, div);
    if(sub) go(depth + 1, ans - ar[depth], add, sub - 1, mul, div);
    if(mul) go(depth + 1, ans * ar[depth], add, sub, mul - 1, div);
    if(div) go(depth + 1, ans / ar[depth], add, sub, mul, div - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> ar[i];
    for(int i=0; i<4; i++) cin >> oper[i];
    
    go(1, ar[0], oper[0], oper[1], oper[2], oper[3]);
    cout << mx << '\n' << mn;
    
    return 0;
}
