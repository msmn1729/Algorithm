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

//https://www.acmicpc.net/problem/9012 괄호

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string s;
        stack<int> stk;
        cin >> s;
        int flag = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ')') {
                if(stk.empty()) flag = 1;
                if(stk.size() && stk.top() == '(') stk.pop();
            }
            else stk.push(s[i]);
        }
        if(stk.size() || flag) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }

    return 0;
}
