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

//https://www.acmicpc.net/problem/2164 카드2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    deque<int> dq;
    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }
    while(dq.size() > 1) {
        dq.pop_front();
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }
    cout << dq.back();

    return 0;
}
