#include <string>
#include <vector>

using namespace std;

int dp[100001];

int go(int n) {
    if(dp[n]) return dp[n];
    if(n <= 1) return n;
    return dp[n] = (go(n-1) + go(n-2))%1234567;
}

int solution(int n) {
    int answer = go(n);
    return answer;
}
