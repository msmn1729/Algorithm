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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/15650 N과 M (2)

int n, m;
int visit[10];
int combi[10];

void go(int start, int depth) {
    if(depth == m) {
        for(int i=0; i<m; i++) {
            cout << combi[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=start; i<=n; i++) {
        if(visit[i]) continue;
        combi[depth] = i;
        visit[i] = 1;
        go(i+1, depth+1);
        visit[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    go(1, 0);
    
    return 0;
}
