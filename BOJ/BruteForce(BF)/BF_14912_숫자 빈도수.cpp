#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14912 숫자 빈도수

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, x, ans = 0;
    cin >> n >> x;
    
    for(int i=1; i<=n; i++) {
        int num = i;
        while(num) {
            if(num % 10 == x) ans++;
            num /= 10;
        }
    }
    cout << ans;
    
    return 0;
}
