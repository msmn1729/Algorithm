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

//https://www.acmicpc.net/problem/16236 아기 상어

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j;
    int d = 0, x = 0, y = 0;
    int ar[20][20] = {};
    int check[20][20] = {};
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int ans = 0;
    pair<int, int> shark_size = {2, 0};
    cin >> n;
    
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> ar[i][j];
            if(ar[i][j] == 9) {
                x = i;
                y = j;
                ar[i][j] = 0;
            }
        }
    }
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > q;
    q.push({0, x, y});
    while(q.size()) {
        auto t = q.top(); q.pop();
        d = get<0>(t);
        x = get<1>(t);
        y = get<2>(t);

        //물고기를 먹을 수 있을 때
        if(0 < ar[x][y] && ar[x][y] < shark_size.first) {
            ar[x][y] = 0;
            shark_size.second++;
            //먹은 물고기 수가 상어의 크기와 같아지면 상어 크기 증가
            if(shark_size.first == shark_size.second) {
                shark_size.first++;
                shark_size.second = 0;
            }
            ans += d;
            d = 0;
            memset(check, 0, sizeof(check));
            while(q.size()) q.pop();
        }

        for(i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(ar[nx][ny] > shark_size.first) continue; //상어보다 큰 물고기 위치로 못감
            if(check[nx][ny]) continue; //방문했던 곳은 패스
            check[nx][ny] = 1;
            q.push({d+1, nx, ny});
        }
    }
    cout << ans << '\n';
    return 0;
}
