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

//https://www.acmicpc.net/problem/15683 감시

int r, c;
int board1[10][10];
int board2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > cctv_pos;

bool OOB(int x, int y) {
    return x<0 || y<0 || x>=r || y>=c;
}

void dfs(int x, int y, int dir) {
    dir %= 4;
    x += dx[dir];
    y += dy[dir];
    if(OOB(x, y) || board2[x][y] == 6) return;
    if(!board2[x][y]) board2[x][y] = 7; //방문처리
    dfs(x, y, dir);
}

void update(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(OOB(x, y) || board2[x][y] == 6) return; //범위초과나 벽이면 종료
        if(board2[x][y]) continue; //이 부분없으면 틀림. 다른 CCTV를 7로 바꾸면 안됨
        board2[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int zero_cnt = 0;
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> board1[i][j];
            if(1 <= board1[i][j] && board1[i][j] <= 5) cctv_pos.push_back({i, j});
            if(board1[i][j] == 0) zero_cnt++;
        }
    }
    
    int four_pow = 1<<(2*cctv_pos.size());
    for(int tmp=0; tmp<four_pow; tmp++) {
        
        for(int k=0; k<r; k++) {
            for(int l=0; l<c; l++) {
                board2[k][l] = board1[k][l]; //배열 복사
            }
        }
        
        int brute = tmp;
        for(int i=0; i<cctv_pos.size(); i++) {
            int x, y;
            tie(x, y) = cctv_pos[i];
            int cctv_type = board2[x][y];
            int dir = brute%4;
            
            if(cctv_type == 1) {
                dfs(x, y, dir);
            }
            else if(cctv_type == 2) {
                if(dir == 0 || dir == 1) continue; //2방향이므로 최적화
                dfs(x, y, dir);
                dfs(x, y, dir+2);
            }
            else if(cctv_type == 3) {
                dfs(x, y, dir);
                dfs(x, y, dir+1);
            }
            else if(cctv_type == 4) {
                dfs(x, y, dir);
                dfs(x, y, dir+1);
                dfs(x, y, dir+2);
            }
            else if(cctv_type == 5) {
                if(dir) continue; //1방향이므로 최적화
                dfs(x, y, dir);
                dfs(x, y, dir+1);
                dfs(x, y, dir+2);
                dfs(x, y, dir+3);
            }
            
            //            if(cctv_type == 1) {
            //                update(x, y, brute);
            //            }
            //            else if(cctv_type == 2) {
            //                update(x, y, brute);
            //                update(x, y, brute+2);
            //            }
            //            else if(cctv_type == 3) {
            //                update(x, y, brute);
            //                update(x, y, brute+1);
            //            }
            //            else if(cctv_type == 4) {
            //                update(x, y, brute);
            //                update(x, y, brute+1);
            //                update(x, y, brute+2);
            //            }
            //            else if(cctv_type == 5) {
            //                update(x, y, brute);
            //                update(x, y, brute+1);
            //                update(x, y, brute+2);
            //                update(x, y, brute+3);
            //            }
            brute /= 4;
        }
        
        int cnt = 0;
        //        cout << "--------\n\n\n";
        for(int k=0; k<r; k++) {
            for(int l=0; l<c; l++) {
                cnt += (board2[k][l] == 0);
                //                cout << board2[k][l] << ' ';
            }
            //            cout << '\n';
        }
        zero_cnt = min(zero_cnt, cnt);
    }
    cout << zero_cnt;
    
    return 0;
}
