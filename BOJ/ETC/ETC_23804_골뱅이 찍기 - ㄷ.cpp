#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << "@@@@@";
        }
        cout << '\n';
    }
    
    for(int i=0; i<n*3; i++) {
        for(int j=0; j<n; j++) {
            cout << "@";
        }
        cout << '\n';
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << "@@@@@";
        }
        cout << '\n';
    }
    
    return 0;
}
