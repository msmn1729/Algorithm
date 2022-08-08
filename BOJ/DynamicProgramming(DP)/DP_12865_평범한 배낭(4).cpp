#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#define ll long long
using namespace std;

struct info {
    int weight, value;
};

int dp[101][100001];

int main() {
    int n, k;
    cin >> n >> k;
    vector<info> item(k+1);
    
    for(int i=1; i<=n; i++) {
        cin >> item[i].weight >> item[i].value;
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(item[i].weight <= j) {
                dp[i][j] = dp[i-1][j-item[i].weight] + item[i].value;
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[n][k];
    
    return 0;
}
