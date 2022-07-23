#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
#define INF 1e9
using namespace std;

struct info {
	int st, ed, cost;
};

int n, m;
int parent[1001];

bool compare(info a, info b) {
	return a.cost < b.cost;
}

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<info> v;
	int st, ed, cost;

	for (int i = 0; i < m; i++) {
		cin >> st >> ed >> cost;
		v.push_back({ st, ed, cost });
	}

	sort(v.begin(), v.end(), compare);

	int ans = 0;
	for (int i = 1; i <= 1001; i++) parent[i] = i;

	for (auto it : v) {
		st = it.st;
		ed = it.ed;
		cost = it.cost;
		if (find(st) == find(ed)) continue;
		merge(st, ed);
		ans += cost;
	}

	cout << ans;

	return 0;
}
