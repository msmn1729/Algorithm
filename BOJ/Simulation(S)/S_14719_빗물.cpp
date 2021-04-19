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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int board[501][501] = {};
    int h, w;
    cin >> h >> w;
    for(int i=0; i<w; i++) {
        int a;
        cin >> a;
        for(int j=0; j<a; j++) {
            board[h-j-1][i] = 1;
        }
    }
    
    int ans = 0;
    for(int i=0; i<h; i++) {
        int flag = 0;
        int cnt = 0;
        for(int j=0; j<w; j++) {
            if(board[i][j] && flag) {
                ans += cnt;
                cnt = 0;
            }
            else if(board[i][j]) {
                flag = 1;
            }
            else if(flag) {
                cnt++;
            }
        }
    }
    cout << ans;
    
    return 0;
}
