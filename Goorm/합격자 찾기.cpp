#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        double avg = 0;
        vector<int> v(n);
        
        for(int i=0; i<n; i++) {
            cin >> v[i];
            avg += v[i];
        }
        avg /= n;
        
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(v[i] >= avg) cnt++;
        }
        cout << cnt << "/" << n << '\n';
    }
    
    return 0;
}
