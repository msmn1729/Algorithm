#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
#define INF 1e9
using namespace std;

vector<int> adj[200001];
vector<int> group, memberCard;
int card[200001], vis[200001];

void dfs(int cur) {
    if(vis[cur]) return;
    vis[cur] = 1;
    group.push_back(cur);
    memberCard.push_back(card[cur]);
    for(auto& nxt : adj[cur]) dfs(nxt);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    
    for(int i=1; i<=n; i++) {
        cin >> card[i];
    }
    
    for(int i=0; i<c; i++) {
        int st, ed;
        cin >> st >> ed;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    
    ll ans = 0;
    for(int cur=1; cur<=n; cur++) {
        if(vis[cur]) continue;
        dfs(cur);
        sort(group.begin(), group.end());
        sort(memberCard.begin(), memberCard.end());
        
        for(int i=0; i<group.size(); i++) {
            ans += abs(group[i] - memberCard[i]);
        }
        group.clear();
        memberCard.clear();
    }
    cout << ans;
    
    return 0;
}
