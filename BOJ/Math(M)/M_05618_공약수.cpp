#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/5618 공약수

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    for(int i=1; i<=v[0]; i++) {
        int flag = 0;
        for(int j=0; j<v.size(); j++) {
            if(v[j] % i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << i << '\n';
    }
    
    return 0;
}
