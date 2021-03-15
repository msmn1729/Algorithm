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

//https://www.acmicpc.net/problem/1992 쿼드트리

int n;
int ar[100][100];

void go(int size, int x, int y) {
    if(size == 0) return;
    int start = ar[x][y];
    int flag = 0;
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(start != ar[i][j]) {
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag) {
        cout << start;
        return; //현재 사이즈만큼 압축 성공시 아래 재귀돌면 안됨
    }
    cout << "(";
    size /= 2;
    go(size, x, y);
    go(size, x, y+size);
    go(size, x+size, y);
    go(size, x+size, y+size);
    cout << ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            ar[i][j] = s[j] - '0';
        }
    }
    go(n, 0, 0);
    
    return 0;
}
