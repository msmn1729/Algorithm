#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int dp[100001] = {1};
    
    for(int i=0; i<money.size(); i++) {
        for(int j=1; j<=n; j++) {
            if(j - money[i] < 0) continue;
            dp[j] += dp[j - money[i]];
            dp[j] %= 1000000007;
        }
    }
    answer = dp[n];
    return answer;
}
