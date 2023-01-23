#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<info> v;
    
    for(int i=0; i<n; i++) {
        string name;
        double height;
        cin >> name >> height;
        v.push_back({name, height});
    }
    
    sort(v.begin(), v.end(), cmp);
    cout << fixed;
    cout.precision(2);
    
    cout << v[k-1].name << ' ' << v[k-1].height;
        
    return 0;
}
