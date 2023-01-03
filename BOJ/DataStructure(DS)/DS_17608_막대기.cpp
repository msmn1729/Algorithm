#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> stk;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int in;
        cin >> in;
        stk.push(in);
    }
    
    int mx = 0, ans = 0;
    while (stk.size()) {
        if(mx < stk.top()) {
            ans++;
            mx = stk.top();
        }
        stk.pop();
    }
    cout << ans;

    return 0;
}
