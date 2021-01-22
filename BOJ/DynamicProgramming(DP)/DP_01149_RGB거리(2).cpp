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

//https://www.acmicpc.net/problem/1149 RGB거리

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, prev_r, prev_g, prev_b, sum_r = 0, sum_g = 0, sum_b = 0;
    cin >> n;
    while(n--) {
        prev_r = sum_r;
        prev_g = sum_g;
        prev_b = sum_b;
        
        cin >> sum_r >> sum_g >> sum_b;
        sum_r += min(prev_g, prev_b);
        sum_g += min(prev_b, prev_r);
        sum_b += min(prev_r, prev_g);
    }
    cout << min(min(sum_r, sum_g), sum_b);

    return 0;
}
