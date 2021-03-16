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

//https://www.acmicpc.net/problem/2667 단지번호붙이기

int ar[30][30];
int n;

int dfs(int x, int y) {
    if(x<0 || y<0 || x>=n || y>=n || ar[x][y] == 0) return 0;
    ar[x][y] = 0;
    return 1 + dfs(x-1, y) + dfs(x, y-1) + dfs(x+1, y) + dfs(x, y+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            ar[i][j] = s[j] - '0';
        }
    }
    vector<int> home_cnt;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(ar[i][j]) home_cnt.push_back(dfs(i, j));
        }
    }
    cout << home_cnt.size() << '\n';
    sort(home_cnt.begin(), home_cnt.end());
    for(int it: home_cnt) cout << it << '\n';
    
    return 0;
}
