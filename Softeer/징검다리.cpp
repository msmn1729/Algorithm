#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 1;
	cin >> n;
	int dp[3001] = {}, ar[3001] = {};

	for(int i=0; i<n; i++) {
		cin >> ar[i];
		int mx = 0;
		for(int j=0; j<i; j++) {
			if(ar[i] > ar[j]) {
				mx = max(mx, dp[j]);
			}
		}
		dp[i] = mx + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
