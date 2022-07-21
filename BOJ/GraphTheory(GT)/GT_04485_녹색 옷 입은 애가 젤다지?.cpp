#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
#define INF 1e9
using namespace std;

int n;
int board[130][130];
int dist[130][130];
int visit[130][130];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = visit[i][j] = 0;
			dist[i][j] = INF;
		}
	}
}

void dijkstra() {
	priority_queue<pair<int, pair<int, int>> > pq;
	pq.push({ board[0][0], {0, 0} });
	dist[0][0] = board[0][0];

	while (pq.size()) {
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visit[nx][ny]) continue;

			if (dist[cx][cy] + board[nx][ny] < dist[nx][ny]) {
				dist[nx][ny] = dist[cx][cy] + board[nx][ny];
				pq.push({ -dist[nx][ny], {nx, ny} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int test_case = 1;; test_case++) {
		cin >> n;
		if (n == 0) break;

		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		dijkstra();
		cout << "Problem " << test_case << ": " << dist[n - 1][n - 1] << '\n';
	}

	return 0;
}
