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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/10250 ACM 호텔

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int h, w, n;
        cin >> h >> w >> n;
        int cnt = 0, i = 0, j = 0;
        bool flag = false;
        for(i=1; i<=w; i++) {
            for(j=1; j<=h; j++) {
                cnt++;
                if(cnt == n) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) {
            int ans = j*100 + i;
            cout << ans << '\n';
        }
    }
    
    return 0;
}
