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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2239 스도쿠

int board[10][10];
int row[10][10];
int col[10][10];
int sub_square[10][10];
vector<int> zero_pos;

void solve(int idx) {
    if(idx == (int)zero_pos.size()) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }
    
    int x = zero_pos[idx] / 9;
    int y = zero_pos[idx] % 9;
    int sub_n = 3 * (x / 3) + y / 3;
    
    for(int num=1; num<=9; num++) {
        if(row[x][num] || col[y][num] || sub_square[sub_n][num]) continue;
        board[x][y] = num;
        row[x][num] = col[y][num] = sub_square[sub_n][num] = 1;
        solve(idx + 1);
        board[x][y] = 0;
        row[x][num] = col[y][num] = sub_square[sub_n][num] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    for(int i=0; i<9; i++) {
        cin >> s;
        for(int j=0; j<9; j++) {
            board[i][j] = s[j] - '0';
            if(board[i][j]) {
                row[i][board[i][j]] = 1;
                col[j][board[i][j]] = 1;
                sub_square[3 * (i / 3) + j / 3][board[i][j]] = 1;
            }
            else zero_pos.push_back(i * 9 + j);
        }
    }
    solve(0);
    
    return 0;
}
