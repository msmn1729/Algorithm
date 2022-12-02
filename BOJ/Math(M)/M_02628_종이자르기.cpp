#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c, r, n;
    cin >> c >> r;
    cin >> n;
    vector<int> transverse = {0, r}, vertical = {0, c};
    
    for(int i=0; i<n; i++) {
        int type, num;
        cin >> type >> num;
        if(type == 0) transverse.push_back(num);
        else vertical.push_back(num);
    }
    
    sort(transverse.begin(), transverse.end());
    sort(vertical.begin(), vertical.end());
    
    int maxTransverse = 0, maxVertical = 0;
    for(int i=1; i<transverse.size(); i++) {
        maxTransverse = max(maxTransverse, transverse[i] - transverse[i-1]);
    }
    
    for(int i=1; i<vertical.size(); i++) {
        maxVertical = max(maxVertical, vertical[i] - vertical[i-1]);
    }
    
    cout << maxTransverse * maxVertical;
    
    return 0;
}
