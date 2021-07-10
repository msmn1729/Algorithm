#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/2748 피보나치 수 2

ll dp[100] = {0, 1};
ll fibo(int n) {
    if(n <= 1) return n;
    if(dp[n]) return dp[n];
    return dp[n] = fibo(n-1) + fibo(n-2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << fibo(n);
    
    return 0;
}
