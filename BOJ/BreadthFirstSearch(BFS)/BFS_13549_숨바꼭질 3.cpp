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
#define INF 2e9

using namespace std;

//https://www.acmicpc.net/problem/13549 숨바꼭질 3

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    int dist[100001] = {};
    cin >> n >> k;
    
    deque<int> dq;
    dq.push_back(n);
    dist[n] = 1;
    
    while(dq.size()) {
        int cur_pos = dq.back();
        dq.pop_back();
        
        for(int nxt: {cur_pos-1, cur_pos+1, cur_pos*2}) {
            if(nxt < 0 || nxt > 1e5) continue;
            if(dist[nxt]) continue;
            if(nxt == cur_pos*2) {
                dist[nxt] = dist[cur_pos] + 1;
                dq.push_back(nxt);
            }
            else {
                dist[nxt] = dist[cur_pos] + 1;
                dq.push_front(nxt);
            }
        }
    }
    cout << dist[k]-1;
    
    return 0;
}
