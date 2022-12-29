#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    int discount = 0;
    cin >> n >> p;
    
    if(n >= 5) {
        discount = 500;
    }
    if(n >= 10) {
        discount = max(discount, int(p * 0.1));
    }
    if(n >= 15) {
        discount = max(discount, 2000);
    }
    if(n >= 20) {
        discount = max(discount, int(p * 0.25));
    }
    cout << max(0, p - discount);
    
    return 0;
}
