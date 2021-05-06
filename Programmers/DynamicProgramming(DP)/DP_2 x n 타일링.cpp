#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int dp[60001] = {0, 1, 2};
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= (1000000007);
    }
    return dp[n];
}
