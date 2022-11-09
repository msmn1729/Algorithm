#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n1, n2;
    cin >> n1 >> n2;
    int d;
    cin >> d;
    
    for(int i=1; i<=d; i++) {
        int half = 0;
        if(i%2) {
            half = n1/2;
            if(n1%2) half++;
            n1 -= half;
            n2 += half;
        }
        else {
            half = n2/2;
            if(n2%2) half++;
            n1 += half;
            n2 -= half;
        }
    }
    cout << n1 << ' ' << n2;
    
    return 0;
}
