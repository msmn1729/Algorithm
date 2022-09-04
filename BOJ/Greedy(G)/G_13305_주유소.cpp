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
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> road(n-1);
    vector<ll> price(n);
    for(int i=0; i<n-1; i++) {
        cin >> road[i];
    }
    
    for(int i=0; i<n; i++) {
        cin >> price[i];
    }
    
    ll prevPrice = price[0];
    for(int i=0; i<n-1; i++) {
        if(prevPrice < price[i]) {
            ans += prevPrice * road[i];
        }
        else {
            // 현재 기름이 더 저렴할 때
            ans += price[i] * road[i];
            prevPrice = price[i];
        }
    }
    
    cout << ans;
    
    return 0;
}
