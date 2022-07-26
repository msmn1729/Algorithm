#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    
    for(int i=0; i<n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    
    int st = 0, ed = 0;
    int sum = 0, ans = 0;
    while(1) {
        if(sum < m) {
            if(ed == n) break; // 부분합이 더이상 커질 수 없는 경우
            sum += v[ed++];
        }
        else {
            sum -= v[st++];
        }
        if(sum == m) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}
