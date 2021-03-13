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

//https://www.acmicpc.net/problem/11729 하노이 탑 이동 순서

void hanoi(int n, int from, int by, int to) {
    if(n == 0) return;
    hanoi(n-1, from, to, by);
    cout << from << ' ' << to << '\n';
    hanoi(n-1, by, from, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << '\n';
    hanoi(n, 1, 2, 3);

    return 0;
}
