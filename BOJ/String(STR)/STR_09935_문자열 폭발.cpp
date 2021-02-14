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

//https://www.acmicpc.net/problem/9935 문자열 폭발

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, bomb, ans;
    cin >> s >> bomb;
    
    int size = (int)bomb.size();
    
    for(int i=0; i<s.size(); i++) {
        ans += s[i];
        if(s[i] == bomb.back()) {
            int idx = (int)ans.size() - size;
            if(idx < 0) continue;
            bool del = true;
            for(int j=0; j<size; j++) {
                if(ans[idx++] != bomb[j]) {
                    del = false;
                    break;
                }
            }
            if(del) for(int j=0; j<size; j++) ans.pop_back();
        }
    }
    if(ans.size()) cout << ans;
    else cout << "FRULA";
    
    return 0;
}
