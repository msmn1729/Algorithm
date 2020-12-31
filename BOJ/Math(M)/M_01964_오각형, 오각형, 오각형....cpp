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

//https://www.acmicpc.net/problem/1964 오각형, 오각형, 오각형...

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //5, 5+7, 5+7+10, 5+7+10+13...
    ll n, ans = 5;
    cin >> n;
    
    for(int i=2; i<=n; i++) {
        ans += 7+(i-2)*3;
        ans %= 45678;
    }
    cout << ans;
    
    return 0;
}
