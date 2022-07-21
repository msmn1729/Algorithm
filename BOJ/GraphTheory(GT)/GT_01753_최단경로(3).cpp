#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
#define INF 2e9
using namespace std;

struct info {
	int ed, cost;
};

vector<info> graph[20001];
int dist[20001];
int visit[20001];
int vCnt, eCnt;
int start;

void dijkstra(int start) {
	fill(dist, dist + vCnt + 1, INF);
	dist[start] = 0;

	// 우선순위 큐
	priority_queue<pair<int, int> > pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur]) continue;
		visit[cur] = 1;

		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i].ed;
			int nxtCost = graph[cur][i].cost;

			if (dist[cur] + nxtCost < dist[nxt]) {
				dist[nxt] = dist[cur] + nxtCost;
				pq.push({ -dist[nxt], nxt });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> vCnt >> eCnt;
	cin >> start;

	for (int i = 0; i < eCnt; i++) {
		int st, ed, cost;
		cin >> st >> ed >> cost;
		graph[st].push_back({ ed, cost });
	}

	dijkstra(start);

	for (int i = 1; i <= vCnt; i++) {
		if (dist[i] == INF) cout << "INF";
		else cout << dist[i];
		cout << '\n';
	}

	return 0;
}
