#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

struct info {
    string name;
    int ko, en, math;
};

bool compare(info a, info b) {
    if(a.ko == b.ko && a.en == b.en && a.math == b.math) return a.name < b.name;
    if(a.ko == b.ko && a.en == b.en) return a.math > b.math;
    if(a.ko == b.ko) return a.en < b.en;
    return a.ko > b.ko;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<info> v;
    info in;
    while(n--) {
        cin >> in.name >> in.ko >> in.en >> in.math;
        v.push_back(in);
    }
    sort(v.begin(), v.end(), compare);
    
    for(auto it : v) {
        cout << it.name << '\n';
    }
    
    return 0;
}
