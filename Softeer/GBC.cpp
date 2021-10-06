#include <iostream>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    vector<int> v1, v2;
    int n, m, section, speed, ans = 0;
    cin >> n >> m;
    
    while(n--) {
        cin >> section >> speed;
        while(section--) v1.push_back(speed);
    }
    
    while(m--) {
        cin >> section >> speed;
        while(section--) v2.push_back(speed);
    }
    
    for(int i=0; i<100; i++) {
        ans = max(ans, v2[i] - v1[i]);
    }
    cout << ans;
    
    return 0;
}
