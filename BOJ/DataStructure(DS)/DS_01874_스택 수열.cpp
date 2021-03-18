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

//https://www.acmicpc.net/problem/1874 스택 수열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    stack<int> stk;
    string ans_stk;
    int n, prev = 1;
    cin >> n;
    
    while(n--) {
        int in;
        cin >> in;
        
        while(1) {
            if(stk.size() && (in < stk.top())) {
                cout << "NO";
                return 0;
            }
            if(stk.size() && (in == stk.top())) {
                stk.pop();
                ans_stk.push_back('-');
                break;
            }
            else {
                stk.push(prev++);
                ans_stk.push_back('+');
            }
        }
    }
    for(char c: ans_stk) cout << c << '\n';
    
    return 0;
}
