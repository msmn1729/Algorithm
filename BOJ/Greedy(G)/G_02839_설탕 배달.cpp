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

//https://www.acmicpc.net/problem/2839 설탕 배달

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, cnt = 0;
    cin >> n;
    
    while(1) {
        if(n % 5 == 0) {
            cout << n/5 + cnt;
            break;
        }
        n -= 3;
        cnt++;
        if(n < 0) {
            cout << -1;
            break;
        }
    }
    
    return 0;
}
