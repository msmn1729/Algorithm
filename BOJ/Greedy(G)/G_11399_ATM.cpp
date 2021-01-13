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
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/11399 ATM

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i;
    int ar[1001] = {};
    cin >> n;
    for(i=0; i<n; i++) cin >> ar[i];
    sort(ar, ar+n);
    reverse(ar, ar+n);
    
    int ans = 0;
    for(i=0; i<n; i++) ans += ar[i]*(i+1);
    cout << ans;
    
    return 0;
}
