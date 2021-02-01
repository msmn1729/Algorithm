#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/16953 A → B

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    vector<pair<int, int> > v;
    v.push_back({a, 1});
    
    while(v.size()) {
        int cur_num = v.back().first;
        int cur_cnt = v.back().second;
        v.pop_back();
        
        if(cur_num == b) {
            cout << cur_cnt;
            return 0;
        }
        if(cur_num <= b/2) v.push_back({cur_num*2, cur_cnt+1});
        if(cur_num <= (b-1)/10) v.push_back({cur_num*10+1, cur_cnt+1});
    }
    cout << -1;
    
    return 0;
}
