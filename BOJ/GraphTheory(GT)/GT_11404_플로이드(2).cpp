#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int ar[101][101] = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			ar[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int st, ed, cost;
		cin >> st >> ed >> cost;
		ar[st][ed] = min(ar[st][ed], cost);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (ar[i][k] + ar[k][j] <= ar[i][j]) ar[i][j] = ar[i][k] + ar[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ar[i][j] == INF) cout << 0 << ' ';
			else cout << ar[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
