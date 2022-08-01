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

void go(int depth) {
    if(depth == n - 1) {
        int result = ar[0];
        int cnt = 0, idx = 0;
        int tmpOper[4];
        for(int i=0; i<4; i++) tmpOper[i] = oper[i];
        
        for(int i=0; i<n - 1; i++) {
            int targetIdx = combi[i];
            if(!tmpOper[targetIdx]) continue;
            cnt++;
            if(targetIdx == 0) {
                result += ar[++idx];
            }
            if(targetIdx == 1) {
                result -= ar[++idx];
            }
            if(targetIdx == 2) {
                result *= ar[++idx];
            }
            if(targetIdx == 3) {
                result /= ar[++idx];
            }
            tmpOper[targetIdx]--;
        }
        if(cnt == n - 1) {
            mn = min(mn, result);
            mx = max(mx, result);
        }
        return;
    }
    
    for(int i=0; i<4; i++) {
        combi[depth] = i;
        go(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> ar[i];
    for(int i=0; i<4; i++) cin >> oper[i];
    
    go(0);
    cout << mx << '\n' << mn;
    
    return 0;
}
