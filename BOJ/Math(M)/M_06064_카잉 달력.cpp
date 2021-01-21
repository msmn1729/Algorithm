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

//https://www.acmicpc.net/problem/6064 카잉 달력

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int m, n, x, y;
    while(t--) {
        cin >> m >> n >> x >> y;
        bool flag = false;
        x--;
        y--;
        for(int i=x; i<=m*n; i+=m) {
            if(i%n == y) {
                cout << i+1 << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << -1 << '\n';
    }
    
    return 0;
}
