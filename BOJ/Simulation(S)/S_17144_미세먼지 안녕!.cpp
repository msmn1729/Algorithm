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

//https://www.acmicpc.net/problem/17144 미세먼지 안녕!

int board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int r, c, t;
int top_air_cleaner_row = -1;
int down_air_cleaner_row;

//1초씩 먼지를 확산시키는 함수
void dustSpread() {
    int tmp_board[51][51] = {};
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[i][j] <= 0) continue;
            int dust = board[i][j];
            int dust_sum = 0;
            for(int dir=0; dir<4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if(ni<0 || nj<0 || ni>=r || nj>=c || board[ni][nj] == -1) continue;
                if(board[ni][nj] == -1) continue;
                tmp_board[ni][nj] += dust / 5;
                dust_sum += dust / 5;
            }
            tmp_board[i][j] += board[i][j] - dust_sum;
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            board[i][j] = tmp_board[i][j];
        }
    }
}

//1초씩 공기순환하는 함수
void airClean() {
    //위쪽 순환
    for(int i=top_air_cleaner_row-1; i>0; i--) board[i][0] = board[i-1][0];
    for(int i=0; i<c-1; i++) board[0][i] = board[0][i+1];
    for(int i=0; i<top_air_cleaner_row; i++) board[i][c-1] = board[i+1][c-1];
    for(int i=c-1; i>1; i--) board[top_air_cleaner_row][i] = board[top_air_cleaner_row][i-1];
    board[top_air_cleaner_row][1] = 0;
    
    //아래쪽 순환
    for(int i=down_air_cleaner_row+1; i<r-1; i++) board[i][0] = board[i+1][0];
    for(int i=0; i<c-1; i++) board[r-1][i] = board[r-1][i+1];
    for(int i=r-1; i>down_air_cleaner_row-1; i--) board[i][c-1] = board[i-1][c-1];
    for(int i=c-1; i>1; i--) board[down_air_cleaner_row][i] = board[down_air_cleaner_row][i-1];
    board[down_air_cleaner_row][1] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> r >> c >> t;
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> board[i][j];
            if(board[i][j] == -1) down_air_cleaner_row = i;
        }
    }
    top_air_cleaner_row = down_air_cleaner_row - 1;

    while(t--) {
        dustSpread();
        board[top_air_cleaner_row][0] = board[down_air_cleaner_row][0] = -1;
        airClean();
    }
    
    int dust_sum = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[i][j] <= 0) continue;
            dust_sum += board[i][j];
        }
    }
    cout << dust_sum;
    
    return 0;
}
