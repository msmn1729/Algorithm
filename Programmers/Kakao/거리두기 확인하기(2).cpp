#include <bits/stdc++.h>
using namespace std;

// 완전탐색 풀이
int dx1[4] = {-1, 1, 0, 0};
int dy1[4] = {0, 0, -1, 1};
int dx2[4] = {-1, -1, 1, 1};
int dy2[4] = {-1, 1, -1, 1};
int dx3[4] = {-2, 2, 0, 0};
int dy3[4] = {0, 0, -2, 2};

bool OOB(int x, int y) {
    return x<0 || y<0 || x>=5 || y>=5;
}

int solve(vector<string>& board) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            char c = board[i][j];
            if(board[i][j] != 'P') continue;
            
            for(int dir=0; dir<4; dir++) {
                int nx = i + dx1[dir];
                int ny = j + dy1[dir];
                if(!OOB(nx, ny) && board[nx][ny] == 'P') return 0;
            }
            for(int dir=0; dir<4; dir++) {
                int nx = i + dx2[dir];
                int ny = j + dy2[dir];
                if(!OOB(nx, ny) && board[nx][ny] == 'P') {
                    if(board[i][ny] != 'X' || board[nx][j] != 'X') return 0;
                }
            }
            for(int dir=0; dir<4; dir++) {
                int nx = i + dx3[dir];
                int ny = j + dy3[dir];
                if(!OOB(nx, ny) && board[nx][ny] == 'P') {
                    nx = i + dx1[dir];
                    ny = j + dy1[dir];
                    if(board[nx][ny] != 'X') return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& p : places) answer.push_back(solve(p));
    return answer;
}