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

//https://www.acmicpc.net/problem/5052 전화번호 목록

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        string s[10001] = {};
        unordered_map<string, int> m;
        for(int i=0; i<n; i++) {
            cin >> s[i];
            m[s[i]] = 1;
        }
        int flag = 0;
        for(int i=0; i<n; i++) {
            string tmp = "";
            for(char c: s[i]) {
                tmp += c;
                if(tmp != s[i] && m[tmp] == 1) {
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }

    return 0;
}
