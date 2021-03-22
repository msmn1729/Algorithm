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

//https://www.acmicpc.net/problem/1316 그룹 단어 체커

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    cin >> n;
    
    while(n--) {
        string s;
        cin >> s;
        s.erase(unique(s.begin(), s.end()), s.end());
        
        int alpa[26] = {};
        int flag = 0;
        for(char c: s) {
            if(alpa[c - 'a']) {
                flag = 1;
                break;
            }
            alpa[c - 'a'] = 1;
        }
        if(!flag) ans++;
    }
    cout << ans;
    
    return 0;
}
