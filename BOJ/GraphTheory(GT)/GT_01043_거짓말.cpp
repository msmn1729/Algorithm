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

//https://www.acmicpc.net/problem/1043 거짓말

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int visit_party[51] = {};
    int n, m, t;
    cin >> n >> m >> t;
    
    queue<int> q;
    for(int i=0; i<t; i++) {
        int in;
        cin >> in;
        q.push({in});
    }
    
    vector<int> party_member[51]; //파티에 속한 사람들
    vector<int> member_party[51]; //사람이 속한 파티들
    for(int i=1; i<=m; i++) {
        int party_num;
        cin >> party_num;
        for(int j=0; j<party_num; j++) {
            int in;
            cin >> in;
            party_member[i].push_back(in);
            member_party[in].push_back(i);
        }
    }
    
    while(q.size()) {
        int cur_man = q.front();
        q.pop();
        
        for(int i=0; i<member_party[cur_man].size(); i++) {
            int nxt_party = member_party[cur_man][i];
            if(visit_party[nxt_party]) continue;
            visit_party[nxt_party] = 1;
            
            for(int j=0; j<party_member[nxt_party].size(); j++) {
                int nxt_man = party_member[nxt_party][j];
                q.push(nxt_man);
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=m; i++) {
        if(visit_party[i]) continue;
        ans++;
    }
    cout << ans;
    
    return 0;
}
