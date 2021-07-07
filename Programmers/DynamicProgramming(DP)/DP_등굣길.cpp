#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ar[101][101];
int dp[101][101];

int solution(int c, int r, vector<vector<int>> puddles) {
    for(auto v: puddles) {
        ar[v[1]][v[0]] = 1;
    }
    
    dp[1][0] = 1;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(ar[i][j]) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % (1000000007);
        }
    }
    
    return dp[r][c];
}