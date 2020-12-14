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

//https://www.acmicpc.net/problem/2010 플러그

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans = 1;
    cin >> n;
    for(int i=0; i<n; i++) {
        int in;
        cin >> in;
        ans += in;
    }
    cout << ans-n;
    
    return 0;
}
