#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<int> v(2);
    cin >> n;
    
    while(n--) {
        int a, b;
        cin >> a >> b;
        if(a > b) v[0]++;
        else if(b > a) v[1]++;
    }
    cout << v[0] << ' ' << v[1];
    
    return 0;
}
