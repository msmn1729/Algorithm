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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1932 정수 삼각형

int n;
int ar[501][501] = {};
int dp[501][501] = {};

int solution(int x, int y) {
    if(x == n) return ar[x][y];
    int &ret = dp[x][y];
    if(ret) return ret;
    return ret = max(solution(x+1, y), solution(x+1, y+1)) + ar[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> ar[i][j];
        }
    }
    cout << solution(1, 1);

    return 0;
}
