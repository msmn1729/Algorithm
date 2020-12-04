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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/1764 듣보잡

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //이분탐색 32ms
    int n, m;
    string s;
    vector<string> v;
    vector<string> ans;
    cin >> n >> m;
    
    while(n--) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    while(m--) {
        cin >> s;
        if(binary_search(v.begin(), v.end(), s)) ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto& i : ans) cout << i << '\n';
    
    //맵사용 60ms
//    int n, m;
//    string s;
//    cin >> n >> m;
//    unordered_map<string, int> list;
//    vector<string> ans;
//    while(n--) {
//        cin >> s;
//        list[s] = 1;
//    }
//    while(m--) {
//        cin >> s;
//        if(list[s]) ans.push_back(s);
//    }
//    sort(ans.begin(), ans.end());
//    cout << ans.size() << '\n';
//    for(auto& i : ans) cout << i << '\n';
    
    return 0;
}
