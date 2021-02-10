#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1167 트리의 지름

vector<pair<int, int> > graph[100001];
int visit[100001] = {};
int max_dist;
int max_vertex;

void dfs(int start, int dist) {
    visit[start] = 1;
    
    if(max_dist < dist) {
        max_dist = dist;
        max_vertex = start;
    }
    
    for(auto it: graph[start]) {
        int nxt = it.first;
        if(visit[nxt]) continue;
        dfs(nxt, dist + it.second);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while(n--) {
        int st, ed, dist;
        cin >> st;
        
        while(1) {
            cin >> ed;
            if(ed == -1) break;
            cin >> dist;
            graph[st].push_back({ed, dist});
            graph[ed].push_back({st, dist}); //이 문제에서는 없어도 통과
        }
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    dfs(max_vertex, 0);
    cout << max_dist;
    
    return 0;
}
