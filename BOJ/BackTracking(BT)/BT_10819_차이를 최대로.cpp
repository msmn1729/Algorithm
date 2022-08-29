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

int combi[10], ar[10], vis[10];
int n;
int ans;

void go(int depth) {
    if(depth == n) {
        int sum = 0;
        for(int i=0; i<n-1; i++) {
            sum += abs(combi[i] - combi[i+1]);
        }
        ans = max(ans, sum);
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        combi[depth] = ar[i];
        go(depth + 1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> ar[i];
    go(0);
    cout << ans;
    
    return 0;
}
