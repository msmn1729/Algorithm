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

//https://www.acmicpc.net/problem/15829 Hashing

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, ans = 0, mul = 1;
    string s;
    cin >> n >> s;
    
    for(int i=0; i<s.size(); i++) {
        ans += (s[i] - 'a' + 1) * mul;
        mul *= 31;
        mul %= 1234567891;
        ans %= 1234567891;
    }
    cout << ans;
    
    return 0;
}
