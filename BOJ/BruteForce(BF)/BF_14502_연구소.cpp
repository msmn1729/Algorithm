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

//https://www.acmicpc.net/problem/14502 연구소

int r, c;
int tmp_board[10][10];
int board[10][10];
int visit[10][10];

int dfs(int x, int y) {
    if(board[x][y] == 1|| visit[x][y] || x<0 || y<0 || x>=r || y>=c) return 0;
    board[x][y] = 2;
    visit[x][y] = 1;
    return 1 + dfs(x-1, y) + dfs(x, y-1) + dfs(x+1, y) + dfs(x, y+1);
}

int virus() {
    int virus_sum = 0;
    //바이러스를 퍼트리기
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[i][j] == 2) {
                virus_sum += dfs(i, j);
            }
        }
    }
    return virus_sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int one_cnt = 0;
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> tmp_board[i][j];
            one_cnt += (tmp_board[i][j] == 1);
        }
    }
    
    int mn = 2e9;
    //O(8^6)
    for(int x1=0; x1<r; x1++) {
        for(int y1=0; y1<c; y1++) {
            for(int x2=0; x2<r; x2++) {
                for(int y2=0; y2<c; y2++) {
                    for(int x3=0; x3<r; x3++) {
                        for(int y3=0; y3<c; y3++) {
                            if(x1 == x2 && y1 == y2) continue;
                            if(x2 == x3 && y2 == y3) continue;
                            if(x3 == x1 && y3 == y1) continue;
                            if(tmp_board[x1][y1] || tmp_board[x2][y2] || tmp_board[x3][y3]) continue;
                            memcpy(board, tmp_board, sizeof(board));
                            memset(visit, 0, sizeof(visit));
                            board[x1][y1] = board[x2][y2] = board[x3][y3] = 1; //벽 3개 세우기
                            mn = min(mn, virus());
                        }
                    }
                }
            }
        }
    }
    
    int ans = r * c - one_cnt - mn - 3;
    cout << ans;
    
    return 0;
}
