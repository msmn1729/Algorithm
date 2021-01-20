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

//https://www.acmicpc.net/problem/1389 케빈 베이컨의 6단계 법칙

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int ar[101][101] = {};
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) ar[i][j] = 1e9;
    }
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ar[a][b] = ar[b][a] = 1;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);
            }
        }
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=1; j<=n; j++) {
            if(i == j) continue;;
            sum += ar[i][j];
        }
        pq.push({sum, i});
    }
    cout << pq.top().second;
    
    return 0;
}
