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

//https://www.acmicpc.net/problem/9663 N-Queen

int n;
int ans;
int visit1[16]; //세로 방향
int visit2[30]; //역슬래시 방향
int visit3[30]; //슬래시 방향

void go(int x) {
    if(x == n) {
        ans++;
        return;
    }
    for(int y=0; y<n; y++) {
        if(visit1[y] || visit2[x+y] || visit3[x-y+n-1]) continue;
        visit1[y] = visit2[x+y] = visit3[x-y+n-1] = 1;
        go(x+1);
        visit1[y] = visit2[x+y] = visit3[x-y+n-1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    go(0);
    cout << ans;
    
    return 0;
}
