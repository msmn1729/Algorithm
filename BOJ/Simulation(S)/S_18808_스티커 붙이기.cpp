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

//https://www.acmicpc.net/problem/18808 스티커 붙이기

int n, m, k;
int r, c;
int board[40][40];
int sticker[10][10];

bool sticking(int sticker_cnt) {
    for(int k=0; k<n; k++) {
        for(int l=0; l<m; l++) {
            int cnt = 0;
            for(int i=k; i<k+r; i++) {
                for(int j=l; j<l+c; j++) {
                    if(i<n && j<m && sticker[i-k][j-l] && board[i][j] == 0) cnt++;
                }
            }
            
            if(cnt == sticker_cnt) {
                for(int i=k; i<k+r; i++) {
                    for(int j=l; j<l+c; j++) {
                        if(sticker[i-k][j-l]) board[i][j] = sticker[i-k][j-l];
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void aryRightRotation() {
    int tmp[10][10] = {};
    int i, j;
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }
    
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            sticker[j][r-i-1] = tmp[i][j];
        }
    }
    swap(r, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        cin >> r >> c;
        int sticker_cnt = 0;
        
        for(int x=0; x<r; x++) {
            for(int y=0; y<c; y++) {
                cin >> sticker[x][y];
                if(sticker[x][y]) sticker_cnt++;
            }
        }
        for(int j=0; j<4; j++) {
            if(sticking(sticker_cnt)) break;
            aryRightRotation();
        }
        for(int j=0; j<10; j++) fill(sticker[j], sticker[j]+10, 0);
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans += board[i][j];
        }
    }
    cout << ans;
    
    return 0;
}
