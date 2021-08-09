#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/20053 최소, 최대 2

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v;
        
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        cout << v.front() << ' ' << v.back() << '\n';
    }
    
    return 0;
}
