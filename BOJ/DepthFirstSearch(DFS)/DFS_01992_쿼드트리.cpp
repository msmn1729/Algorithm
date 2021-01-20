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

//https://www.acmicpc.net/problem/1992 쿼드트리

int ar[64][64];

void dfs(int x, int y, int size) {
    if(size == 0) return;
    
    int start = ar[x][y];
    bool flag = false;
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(start != ar[i][j]) {
                flag = true;
                break;
            }
        } if(flag) break;
    }
    
    if(!flag) {
        cout << start;
        return;
    }
    
    size /= 2;
    cout << '(';
    for(int i=0; i<2; i++) for(int j=0; j<2; j++) dfs(x+size*i, y+size*j, size);
    cout << ')';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            ar[i][j] = s[j] - '0';
        }
    }
    dfs(0, 0, n);
    
    return 0;
}
