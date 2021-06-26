#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<int> v;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        v.insert(v.end()-a, i);
    }
    
    for(int it: v) cout << it << ' ';
    
    return 0;
}
