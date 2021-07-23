#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c;
    int ar[51][51] = {};
    cin >> r >> c;
    
    for(int i=0; i<r; i++) {
        string s;
        cin >> s;
        for(int j=0; j<c; j++) ar[i][j] = s[j] - '0';
    }
    
    for(int size=min(r, c)-1; size>=0; size--) {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i+size >= r || j+size >= c) continue;
                if(ar[i][j] == ar[i+size][j]
                   && ar[i][j+size] == ar[i+size][j+size]
                   && ar[i][j] == ar[i+size][j+size]) {
                    cout << (size+1)*(size+1);
                    return 0;
                }
            }
        }
    }
    
    return 0;
}
