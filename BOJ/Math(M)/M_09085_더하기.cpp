#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/9085 더하기

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        while(n--) {
            int a;
            cin >> a;
            sum += a;
        }
        cout << sum << '\n';
    }
    
    return 0;
}
