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
    int height, idx1, idx2;
};

bool compare(info i1, info i2) {
    return i1.height > i2.height;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<int> v;
    vector<info> vInfo;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            vInfo.push_back({v[i] + v[j], i, j});
        }
    }
    sort(vInfo.begin(), vInfo.end(), compare);
    
    int ans = 2e9;
    for(int i=0; i<vInfo.size(); i++) {
        for(int j=i+1; j<vInfo.size(); j++) {
            if(vInfo[i].idx1 == vInfo[j].idx1) continue;
            if(vInfo[i].idx1 == vInfo[j].idx2) continue;
            if(vInfo[i].idx2 == vInfo[j].idx1) continue;
            if(vInfo[i].idx2 == vInfo[j].idx2) continue;
            ans = min(ans, vInfo[i].height - vInfo[j].height);
            break;
        }
    }
    cout << ans;
    
    return 0;
}
