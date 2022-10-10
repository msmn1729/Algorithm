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

    int n, m;
    cin >> n >> m;
    map<int, string> info;
    string name;
    int value;
    
    for(int i=0; i<n; i++) {
        cin >> name >> value;
        info.insert({value, name}); // 키값 중복 방지
    }
    
    for(int i=0; i<m; i++) {
        int power;
        cin >> power;
        map<int, string>::iterator it = info.lower_bound(power);
        cout << it->second << '\n';
    }
    
    return 0;
}
