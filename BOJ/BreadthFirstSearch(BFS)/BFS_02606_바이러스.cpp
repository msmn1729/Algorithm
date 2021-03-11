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

//https://www.acmicpc.net/problem/2606 바이러스

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v[101];
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int visit[101] = {};
    int ans = 0;
    queue<int> q;
    visit[1] = 1;
    q.push(1);
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<v[cur].size(); i++) {
            int nxt = v[cur][i];
            if(visit[nxt]) continue;
            q.push(nxt);
            visit[nxt] = 1;
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}
