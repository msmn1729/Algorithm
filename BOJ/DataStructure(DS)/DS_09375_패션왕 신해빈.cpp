#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/9375 패션왕 신해빈

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        string name, type;
        unordered_map<string, int> um;
        
        for(int i=0; i<n; i++) {
            cin >> name >> type;
            um[type]++;
        }
        
        int ans = 1;
        for(auto it : um) {
            ans *= (it.second+1);
        }
        cout << ans-1 << '\n';
    }
    
    return 0;
}
