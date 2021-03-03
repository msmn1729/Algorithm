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
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/12849 본대 산책

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dp[8] = {1};
    //0~7 전산 미래 신양 진리 한경 학관 형남
    vector<int> link[8] = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3, 5},
        {1, 2, 4, 5},
        {3, 5, 6},
        {2, 3, 4, 7},
        {4, 7},
        {5, 6}
    };
    
    int d;
    cin >> d;
    while(d--) {
        int cur[8] = {};
        for(int j=0; j<8; j++) {
            for(int k=0; k<link[j].size(); k++) {
                int idx = link[j][k];
                cur[j] += dp[idx];
                cur[j] %= 1000000007;
            }
        }
        memcpy(dp, cur, sizeof(dp));
    }
    cout << dp[0];
    
    return 0;
}
