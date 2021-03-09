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

//https://www.acmicpc.net/problem/12100 2048 (Easy)

int n;
int board[20][20];
int tmp_board[20][20];

void upShift() {
    for(int i=0; i<n; i++) {
        vector<int> v;
        for(int j=0; j<n; j++) {
            if(!board[j][i]) continue;
            if(v.size() && v.back() == board[j][i]) {
                v.back() *= 2;
                v.push_back(-1);
            }
            else v.push_back(board[j][i]);
        }
        for(int j=0; j<v.size(); j++) if(v[j] == -1) v.erase(v.begin() + j);
        for(int j=0; j<n; j++) {
            if(j<v.size()) board[j][i] = v[j];
            else board[j][i] = 0;
        }
    }
}

void rightRotation() {
    int tmp[20][20] = {};
    memcpy(tmp, board, sizeof(tmp));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) board[j][n-i-1] = tmp[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> tmp_board[i][j];
    
    int mx = 0;
    int four_pow = 1<<(2*5);
    for(int i=0; i<four_pow; i++) {
        memcpy(board, tmp_board, sizeof(board));
        int tmp = i;
        for(int j=0; j<5; j++, tmp/=4) {
            int brute = tmp % 4;
            while(brute--) rightRotation();
            upShift();
        }
        for(int x=0; x<n; x++) for(int y=0; y<n; y++) mx = max(mx, board[x][y]);
    }
    cout << mx;
    
    return 0;
}
