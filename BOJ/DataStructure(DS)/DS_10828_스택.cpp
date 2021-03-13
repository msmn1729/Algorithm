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

//https://www.acmicpc.net/problem/10828 스택

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> stk;
    int n;
    cin >> n;
    while(n--) {
        int a;
        string s;
        cin >> s;
        if(s == "push") {
            cin >> a;
            stk.push(a);
        }
        else if(s == "pop") {
            if(stk.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << stk.top();
            cout << '\n';
            stk.pop();
        }
        else if(s == "size") {
            cout << stk.size();
            cout << '\n';
        }
        else if(s == "empty") {
            if(stk.size()) cout << 0;
            else cout << 1;
            cout << '\n';
        }
        else if(s == "top") {
            if(stk.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << stk.top();
            cout << '\n';
        }
    }

    return 0;
}
