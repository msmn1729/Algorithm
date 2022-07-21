#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

struct info {
	int st, ed, cost;
};

int parent[101010];
int vCnt, eCnt;

void init() {
	for (int i = 1; i <= vCnt; i++) {
		parent[i] = i;
	}
}

bool compare(info a, info b) {
	return a.cost < b.cost;
}

// 파인드
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

// 유니온
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> vCnt >> eCnt;
		init();
		int st, ed, cost;
		ll ans = 0;
		vector<info> v;

		while (eCnt--) {
			cin >> st >> ed >> cost;
			v.push_back({ st, ed, cost });
		}

		sort(v.begin(), v.end(), compare);

		for (auto it : v) {
			st = it.st;
			ed = it.ed;
			cost = it.cost;
			
			if (find(st) == find(ed)) continue;
			merge(st, ed);
			ans += cost;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}
