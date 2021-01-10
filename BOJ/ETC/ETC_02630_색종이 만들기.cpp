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

//https://www.acmicpc.net/problem/2630 색종이 만들기

int n, board[130][130];
int ans_white, ans_blue;

void solve(int x, int y, int size) {
    if(size == 0) return;
    
    int i, j;
    int cnt_white = 0, cnt_blue = 0;
    
    for(i=x; i<x+size; i++) {
        for(j=y; j<y+size; j++) {
            if(board[i][j]) cnt_blue++;
            else cnt_white++;
        }
    }
    if(size*size == cnt_blue) {
        ans_blue++;
        return;
    }
    if(size*size == cnt_white) {
        ans_white++;
        return;
    }
    
    size /= 2;
    solve(x, y, size);
    solve(x, y+size, size);
    solve(x+size, y, size);
    solve(x+size, y+size, size);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j;
    cin >> n;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    solve(0, 0, n);
    cout << ans_white << '\n' << ans_blue;
    
    return 0;
}
