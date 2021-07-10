#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// www.acmicpc.net/problem/2003 수들의 합 2

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    int st = 0, ed = 0, ans = 0;
    sum = 0;
    while(1) {
        if(sum > m) sum -= v[st++];
        else {
            if(ed == n) break; // 부분합이 m보다 작은데 ed가 이미 끝에 가있으면 부분합이 더이상 커질 수 없음
            sum += v[ed++];
        }
        if(sum == m) ans++;
    }
    cout << ans;
    return 0;
}
