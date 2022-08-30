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
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    stack<int> stk;
    vector<int> ans(n);
    
    for(int i=(int)v.size()-1; i>=0; i--) {
        while(stk.size() && stk.top() <= v[i]) {
            stk.pop();
        }
        if(stk.empty()) ans[i] = -1;
        else ans[i] = stk.top();
        stk.push(v[i]);
    }
    
    for(int i=0; i<n; i++) cout << ans[i] << ' ';
    
    return 0;
}
