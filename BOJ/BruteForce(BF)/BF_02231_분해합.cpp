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

//https://www.acmicpc.net/problem/2231 분해합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<n; i++) {
        int tmp = i;
        int sum = tmp;
        while(tmp) {
            sum += tmp%10;
            tmp /= 10;
        }
        if(sum == n) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
