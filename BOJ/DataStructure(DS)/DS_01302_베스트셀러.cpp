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
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    map<string, int> m;
    int mx = 0;
    
    while(n--) {
        cin >> s;
        m[s]++;
        mx = max(mx, m[s]);
    }
    
    for(auto it : m) {
        if(it.second == mx) {
            cout << it.first;
            return 0;
        }
    }
    
    return 0;
}
