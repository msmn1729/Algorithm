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

//https://www.acmicpc.net/problem/1914 하노이 탑

string stringSum(string a, string b) {
    int sum = 0;
    string ret = "";
    while(sum || a.size() || b.size()) {
        if(a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret += sum%10 + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

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
    string ans = "1";
    for(int i=0; i<n; i++) ans = stringSum(ans, ans);
    ans[ans.size() - 1] -= 1;
    cout << ans << '\n';
    if(n <= 20) hanoi(n, 1, 2, 3);

    return 0;
}
