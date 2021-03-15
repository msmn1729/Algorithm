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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2630 색종이 만들기

int n;
int ar[130][130];
int ans[2];

void go(int size, int x, int y) {
    if(size == 0) return;
    
    int start_color = ar[x][y];
    bool flag = 0;
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(ar[i][j] != start_color) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag) {
        ans[start_color]++;
        return;
    }
    size /= 2;
    go(size, x, y);
    go(size, x, y+size);
    go(size, x+size, y);
    go(size, x+size, y+size);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> ar[i][j];
        }
    }
    go(n, 0, 0);
    cout << ans[0] << '\n' << ans[1];
    
    return 0;
}
