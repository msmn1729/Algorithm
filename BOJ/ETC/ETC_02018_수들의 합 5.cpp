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
#include <unordered_map>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int st = 1, ed = 1;
    int sum = 0, ans = 0;;
    
    while(st <= n) {
        if(sum <= n) {
            sum += ed;
            ed++;
        }
        else {
            sum -= st;
            st++;
        }
        if(sum == n) {
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}
