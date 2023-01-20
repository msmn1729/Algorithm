#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int fibo(int n) {
    if(n <= 2) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    cout << fibo(n) << ' ' << n - 2;
    
    return 0;
}
