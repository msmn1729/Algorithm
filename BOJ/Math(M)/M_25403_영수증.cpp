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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    int n;
    cin >> x >> n;
    for(int i=0; i<n; i++) {
        int price, cnt;
        cin >> price >> cnt;
        x -= (price * cnt);
    }
    if(x == 0) cout << "Yes";
    else cout << "No";
    
    return 0;
}
