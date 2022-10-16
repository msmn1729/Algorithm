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

bool cmp(string a, string b) {
    if(a.size() == b.size()) return a.compare(b) < 0;
    return a.size() < b.size();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), cmp);
    cout << v[k-1];
    
    return 0;
}
