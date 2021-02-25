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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2495 연속구간

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		int ans = 1;
		int cnt = 1;
		for (int j = 0; j < 7; j++) {
			if (s[j] == s[j + 1]) cnt++;
			else cnt = 1;
			ans = max(ans, cnt);
		}
		cout << ans << '\n';
	}

	return 0;
}