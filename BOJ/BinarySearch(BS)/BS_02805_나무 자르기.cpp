#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/2805 나무 자르기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, i, mx = -2e9;
    cin >> n >> m;
    vector<int> v;
    for(i=0; i<n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
        mx = max(mx, in);
    }
    
    int low = 0, high = mx, mid = 0, ans = 0;
    while(low <= high) {
        mid = (low+high)/2;
        
        ll sum = 0;
        for(i=0; i<n; i++) {
            if(v[i]-mid > 0) {
                sum += v[i]-mid;
            }
        }
        if(sum >= m) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout << ans;
    
    return 0;
}
