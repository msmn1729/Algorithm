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
    for(int i=0; i<t; i++) {
        cin >> n;
        string s = to_string(n);
        string pow = to_string(n*n);
        
        int cnt = 0;
        for(int j=0; j<s.size(); j++) {
            if(s[s.size()-j-1] == pow[pow.size()-j-1]) cnt++;
            else break;
        }
        if(cnt == s.size()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
