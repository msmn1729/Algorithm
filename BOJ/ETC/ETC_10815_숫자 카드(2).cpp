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

//https://www.acmicpc.net/problem/10815 숫자 카드

int num[20000001] = {};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a;
    cin >> n;
    while(n--) {
        cin >> a;
        a += 1e7;
        num[a] = 1;
    }
    
    cin >> m;
    while(m--) {
        cin >> a;
        a += 1e7;
        if(num[a]) cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    return 0;
}
