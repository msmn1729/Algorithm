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

//https://www.acmicpc.net/problem/10830 행렬 제곱

int mat[6][6];
int ans[6][6];
ll n, b;

void matMul(int a[6][6], int b[6][6]) {
    int tmp[6][6] = {};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= 1000;
            }
        }
    }
    memcpy(a, tmp, sizeof(tmp));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> b;
    
    int two = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
        ans[i][i] = 1;
    }
    
    while(b) {
        int bit = b % 2;
        if(bit) matMul(ans, mat);
        matMul(mat, mat); //항상 거듭제곱
        two *= 2;
        b /= 2;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
