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
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    map<int, int> m;
    int intersection = 0;
    
    for(int i=0; i<a; i++) {
        int num;
        cin >> num;
        m[num]++;
    }
    
    for(int i=0; i<b; i++) {
        int num;
        cin >> num;
        if(m[num]) intersection++;
    }

    int ans = a - intersection + b - intersection;
    cout << ans;

    return 0;
}
