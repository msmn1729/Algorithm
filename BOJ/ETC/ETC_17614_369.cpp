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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/17614 369

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    int cnt = 0;
    for(int i=3; i<=n; i++) {
        int tmp = i;
        while(tmp) {
            if(tmp%10 == 3 || tmp%10 == 6 || tmp%10 == 9) cnt++;
            tmp /= 10;
        }
    }
    cout << cnt;
    
    return 0;
}
