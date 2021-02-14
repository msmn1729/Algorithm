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
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1748 수 이어 쓰기 1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int ans = 0;
    cin >> n;
    
    int ar[10] = {};
    int ten = 1;
    for(int i=1; i<=9; i++) {
        ar[i] = 9 * ten;
        ten *= 10;
    }
    
    for(int i=1; i<=9; i++) {
        if(n < ar[i]) {
            ans += n*i;
            break;
        }
        n -= ar[i];
        ans += ar[i]*i;
    }
    
    cout << ans;
    
    return 0;
}
