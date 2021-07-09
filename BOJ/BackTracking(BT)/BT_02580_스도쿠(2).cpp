#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/2580 스도쿠

int board[10][10];
int row_vis[10][10]; // [a][b] : a행에 b숫자가 쓰였는지 확인
int col_vis[10][10];
int square_vis[10][10];

int zero_cnt;
vector<int> zero_idx;

void go(int idx) {
    if(idx == zero_idx.size()) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    // 언팩킹
    int x = zero_idx[idx] / 9;
    int y = zero_idx[idx] % 9;
    int square_no = (x/3)*3 + (y/3) + 1;
    // 넣을 수 있는 숫자 확인
    for(int num=1; num<=9; num++) {
        if(row_vis[x][num] || col_vis[y][num] || square_vis[square_no][num]) continue;
        row_vis[x][num] = col_vis[y][num] = square_vis[square_no][num] = 1;
        board[x][y] = num;
        go(idx+1);
        row_vis[x][num] = col_vis[y][num] = square_vis[square_no][num] = 0;
        board[x][y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // 가로, 세로, 작은 사각형을 매번 체크하면 9*3씩 항상 확인 해야함
    // visit로 해결 가능
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int n;
            cin >> n;
            if(n == 0) zero_idx.push_back(i*9 + j); // 0~80으로 팩킹
            board[i][j] = n;
            row_vis[i][n] = col_vis[j][n] = 1;
            // 사각형 번호 1~9
            int square_no = (i/3)*3 + (j/3) + 1;
            square_vis[square_no][n] = 1;
        }
    }
    go(0);
    return 0;
}
