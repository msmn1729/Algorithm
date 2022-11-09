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

typedef struct {
    string name;
    double height;
} info;

bool cmp(info a, info b) {
    if(a.name == b.name) return a.height < b.height;
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<info> v(n);
    
    for(int i=0; i<n; i++) {
        cin >> v[i].name >> v[i].height;
    }
    
    sort(v.begin(), v.end(), cmp);
    cout << fixed;
    cout.precision(2);
    cout << v[k-1].name << ' ' << v[k-1].height;
    
    return 0;
}
