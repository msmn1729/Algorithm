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
    
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 1;
    for(int i=1; i<s.size(); i++) {
        if(s[i] == s[i-1]) continue;
        ans++;
    }
    cout << ans;
    
    return 0;
}
