#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[101010];

typedef struct info {
	int st, ed, cost;
};

bool compare(info a, info b) {
	return a.cost < b.cost;
}

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else  parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, ans = 0;
	int st, ed, cost;
	vector<info> v;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) parent[i] = i;
	while (m--) {
		cin >> st >> ed >> cost;
		v.push_back({ st, ed, cost });
	}

	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	for (auto it : v) {
		st = it.st;
		ed = it.ed;
		cost = it.cost;

		if (find(st) == find(ed)) continue;
		if (cnt == n - 2) break;
		merge(st, ed);
		ans += cost;
		cnt++;
	}

	cout << ans;
	
	return 0;
}
