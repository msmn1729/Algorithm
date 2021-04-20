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

ll answer;
vector<vector<int> > graph;
vector<ll> costSum;

void dfs(int cur, int parent) {
    for(int i=0; i<graph[cur].size(); i++) {
        int nxt = graph[cur][i];
        if(nxt == parent) continue;
        dfs(nxt, cur);
    }
    costSum[parent] += costSum[cur];
    answer += abs(costSum[cur]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    for(int i=0; i<a.size(); i++) {
        costSum.push_back(a[i]);
    }
    int sum = 0;
    for(int i: a) {
        sum += i;
    }
    if(sum) return -1;
    
    graph.resize(a.size());
    
    for(int i=0; i<edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(0, 0);
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cout << solution({-5, 0, 2, 1, 2}, {{0, 1}, {3, 4}, {2, 3}, {0, 3}});
    
    return 0;
}
