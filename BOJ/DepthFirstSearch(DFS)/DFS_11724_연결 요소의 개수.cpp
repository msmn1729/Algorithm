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

using namespace std;

//https://www.acmicpc.net/problem/11724 연결 요소의 개수

vector<int> ar[1001];
bool visit[1001];

void dfs(int now) {
    visit[now] = true;
    for(int i=0; i<ar[now].size(); i++) {
        int next = ar[now][i];
        if(visit[next]) continue;
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, i;
    cin >> n >> m;
    for(i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    
    int ans = 0;
    for(i=1; i<=n; i++) {
        if(visit[i]) continue;
        dfs(i);
        ans++;
    }
    cout << ans;
    
    return 0;
}
