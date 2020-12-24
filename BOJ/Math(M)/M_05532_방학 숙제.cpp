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

//https://www.acmicpc.net/problem/5532 방학 숙제

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, a, b, c, d, ans = 0, math = 0, korean = 0;
    cin >> l >> a >> b >> c >> d;
    
    math = ceil((double)a/c);
    korean = ceil((double)b/d);
    ans = l - max(math, korean);
    cout << ans;
    
    return 0;
}

