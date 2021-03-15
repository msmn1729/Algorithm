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

//https://www.acmicpc.net/problem/2798 블랙잭

int ans;
int n, m;
int combi[3];
int visit[101];
int ar[101] = {};
int mn = 2e9;

void go(int idx, int depth) {
    if(depth == 3) {
        int sum = 0;
        for(int i=0; i<3; i++) sum += combi[i];
        if(mn > m-sum && m-sum >= 0) {
            mn = m-sum;
            ans = sum;
        }
        return;
    }
    for(int i=idx; i<n; i++) {
        if(visit[i]) continue;
        visit[i] = 1;
        combi[depth] = ar[i];
        go(i+1, depth+1);
        visit[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> ar[i];
    go(0, 0);
    cout << ans;
    
    return 0;
}
