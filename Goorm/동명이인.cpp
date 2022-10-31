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

    int n, ans = 0;
    string target;
    cin >> n >> target;
    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        if(s.find(target) == string::npos) continue;
        ans++;
    }
    cout << ans;

    return 0;
}
