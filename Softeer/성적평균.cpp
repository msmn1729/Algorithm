#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ar[1000001] = {};
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
        ar[i] += ar[i-1];
    }
    
    for(int i=0; i<k; i++) {
        int st, ed;
        cin >> st >> ed;
        double ans = (ar[ed] - ar[st-1]) / double(ed - st + 1);
        printf("%.2f\n", ans);
    }
    
    return 0;
}
