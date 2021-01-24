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

//https://www.acmicpc.net/problem/1780 종이의 개수

int ar[3000][3000];
int n;
int ans_zero, ans_minus_one, ans_plus_one;

void dfs(int x, int y, int size) {
    if(size == 0) return;
    
    int zero_cnt = 0, minus_one_cnt = 0, plus_one_cnt = 0;
    int i, j;
    for(i=x; i<x+size; i++) {
        for(j=y; j<y+size; j++) {
            if(ar[i][j] == -1) minus_one_cnt++;
            else if(ar[i][j] == 0) zero_cnt++;
            else if(ar[i][j] == 1) plus_one_cnt++;
        }
    }
    
    if(minus_one_cnt == size*size) {
        ans_minus_one++;
        return;
    }
    else if(zero_cnt == size*size) {
        ans_zero++;
        return;
    }
    else if(plus_one_cnt == size*size) {
        ans_plus_one++;
        return;
    }
    
    size /= 3;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            dfs(x + size*i, y + size*j, size);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j;
    cin >> n;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> ar[i][j];
        }
    }
    dfs(0, 0, n);
    cout << ans_minus_one << '\n' << ans_zero << '\n' << ans_plus_one;
    
    return 0;
}
