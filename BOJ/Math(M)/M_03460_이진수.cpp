#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		int tmp = n;
		int cnt = 0;
		while (tmp) {
			if (tmp % 2 == 1) cout << cnt << ' ';
			cnt++;
			tmp /= 2;
		}
		cout << '\n';
	}

	return 0;
}
