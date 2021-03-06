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

//https://www.acmicpc.net/problem/18119 단어 암기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    int cur_bit = ~0;
    vector<int> v;
    cin >> n >> m;
    
    while(n--) {
        string s;
        cin >> s;
        int bit = 0;
        for(int i=0; i<s.length(); i++) {
            int pos = s[i] - 'a';
            bit |= 1 << pos;
        }
        v.push_back(bit);
    }
    
    while(m--) {
        char c;
        cin >> c >> c;
        int pos = c - 'a';
        cur_bit ^= (1 << pos);
        int cnt = 0;
        for(int it: v) if(it == (cur_bit & it)) cnt++;
        cout << cnt << '\n';
    }
    
    return 0;
}
