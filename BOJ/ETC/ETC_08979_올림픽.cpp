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
    int num, gold, silver, bronze;
} info;

bool cmp(info a, info b) {
    if(a.gold == b.gold && a.silver == b.silver) {
        return a.bronze > b.bronze;
    }
    else if(a.gold == b.gold) {
        return a.silver > b.silver;
    }
    else {
        return a.gold > b.gold;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<info> v;
    
    for(int i=0; i<n; i++) {
        int num, gold, silver, bronze;
        cin >> num >> gold >> silver >> bronze;
        v.push_back({num, gold, silver, bronze});
    }
    sort(v.begin(), v.end(), cmp);
    
    int rank = 0;
    for(int i=0; i<n; i++) {
        if(k == v[i].num) {
            rank = i;
            break;
        }
    }
    
    int ans = 1;
    for(int i=0; i<n; i++) {
        if(v[rank].gold == v[i].gold && v[rank].silver == v[i].silver && v[rank].bronze == v[i].bronze) {
            ans = i+1;
            break;
        }
    }
    cout << ans;

    return 0;
}
