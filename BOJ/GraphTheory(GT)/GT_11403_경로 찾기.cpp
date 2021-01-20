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

//https://www.acmicpc.net/problem/11403 경로 찾기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int ar[101][101] = {};
    int i, j, k;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> ar[i][j];
        }
    }
    
    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                if(ar[i][k] && ar[k][j]) ar[i][j] = 1;
            }
        }
    }
    
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
