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

//https://www.acmicpc.net/problem/1654 랜선 자르기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, k, i, mx = -2e9;
    vector<ll> v;
    cin >> k >> n;
    
    for(i=0; i<k; i++) {
        ll in;
        cin >> in;
        v.push_back(in);
        mx = max(mx, in);
    }
    
    ll low = 1, high = mx, mid, ans = 0;
    while(low <= high) {
        mid = (low+high)/2;
        
        ll cnt = 0;
        for(i=0; i<k; i++) {
            cnt += v[i]/mid;
        }
        if(cnt >= n) {
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
