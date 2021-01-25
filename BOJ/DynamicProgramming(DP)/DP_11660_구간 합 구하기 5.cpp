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
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/11660 구간 합 구하기 5

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, i, j;
    int ar[1100][1100] = {};
    cin >> n >> m;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cin >> ar[i][j];
            ar[i][j] += ar[i][j-1] + ar[i-1][j] - ar[i-1][j-1];
        }
    }

    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = ar[x2][y2] - ar[x1-1][y2] - ar[x2][y1-1] + ar[x1-1][y1-1];
        cout << ans << '\n';
    }

    return 0;
}
