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

//https://www.acmicpc.net/problem/18258 큐 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    queue<int> q;
    
    while(n--) {
        string s;
        cin >> s;
        if(s == "push") {
            int a;
            cin >> a;
            q.push(a);
        }
        else if(s == "pop") {
            if(q.size()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if(s == "size") {
            cout << q.size() << '\n';
        }
        else if(s == "empty") {
            if(q.size()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if(s == "front") {
            if(q.size()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(s == "back") {
            if(q.size()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}
