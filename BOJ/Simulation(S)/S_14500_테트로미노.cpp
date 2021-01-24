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

//https://www.acmicpc.net/problem/14500 테트로미노

int r, c;
int tetromino[5][4][2] =
{ {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {0, 1}, {0, 2},{1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}}
};

void upDown(int ar[501][501]) {
    int tmp[501][501] = {};
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[i][j] = ar[i][j];
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            ar[i][j] = tmp[r-i-1][j];
        }
    }
}

void leftRight(int ar[501][501]) {
    int tmp[501][501] = {};
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[i][j] = ar[i][j];
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            ar[i][j] = tmp[i][c-j-1];
        }
    }
}

void rightTurn(int ar[501][501]) {
    int tmp[501][501] = {};
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[i][j] = ar[i][j];
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            ar[j][r-i-1] = tmp[i][j];
        }
    }
    int tmp_num = r;
    r = c;
    c = tmp_num;
}

int search(int ar[501][501], int x, int y) {
    int mx = -2e9;
    for(int i=0; i<5; i++) {
        int sum = 0;
        for(int j=0; j<4; j++) {
            int nx = x + tetromino[i][j][0];
            int ny = y + tetromino[i][j][1];
            if(nx >= r || ny >= c) break;
            sum += ar[nx][ny];
        }
        mx = max(mx, sum);
    }
    return mx;
}

int solve(int ar[501][501]) {
    int mx = -2e9;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) mx = max(mx, search(ar, i, j));
    }
    return mx;
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int ar[501][501] = {};
    int ans = -2e9;
    cin >> r >> c;
    for(i=0; i<r; i++) for(j=0; j<c; j++) cin >> ar[i][j];
    
    for(i=0; i<4; i++) {
        //1: 처음 입력
        ans = max(ans, solve(ar));
        
        //2: 위아래 반전
        upDown(ar);
        ans = max(ans, solve(ar));
        
        //3: 상하 원상복구 후 좌우반전
        upDown(ar);
        leftRight(ar);
        ans = max(ans, solve(ar));
        
        //4: 좌우 원상복구 후 턴
        leftRight(ar);
        rightTurn(ar);
    }
    cout << ans;
    return 0;
}
