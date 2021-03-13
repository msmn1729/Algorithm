#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/10773 제로

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> stk;
    int n;
    cin >> n;
    
    while(n--) {
        int a;
        cin >> a;
        if(a) stk.push(a);
        else stk.pop();
    }
    
    int ans = 0;
    while(stk.size()) {
        ans += stk.top();
        stk.pop();
    }
    cout << ans;

    return 0;
}
