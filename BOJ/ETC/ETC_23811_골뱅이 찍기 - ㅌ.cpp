#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int n;

void printPatten(int cnt) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<cnt; k++) cout << "@";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    printPatten(5);
    printPatten(1);
    printPatten(5);
    printPatten(1);
    printPatten(5);
    
    return 0;
}
