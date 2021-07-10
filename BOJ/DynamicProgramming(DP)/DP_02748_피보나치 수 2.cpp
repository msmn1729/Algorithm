#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/2748 피보나치 수 2

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    ll prev = 0, cur = 1;
    while(n--) {
        cur = cur + prev;
        prev = cur - prev;
    }
    cout << prev;
    
    return 0;
}
