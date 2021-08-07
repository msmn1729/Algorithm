#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2800 괄호 제거

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    vector<pii> bracket;
    stack<int> stk;
    string s; cin >> s;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')') {
            bracket.push_back({stk.top(), i});
            stk.pop();
        }
    }
    
    int n = (int)bracket.size();
    int limit = (1 << n);
    vector<string> ans;
    
    for(int bit=1; bit<limit; bit++) { // <= 안해도되나?
        string tmp = s;
        for(int i=0; i<n; i++) {
            if(bit & (1 << i)) tmp[bracket[i].first] = tmp[bracket[i].second] = '.';
        }
        string newStr = "";
        for(char c : tmp) {
            if(c == '.') continue;
            newStr += c;
        }
        ans.push_back(newStr);
    }
    sort(ans.begin(), ans.end());
    
    // 중복제거 방법 택 1
    //    auto it = unique(ans.begin(), ans.end());
    //    ans.erase(it, ans.end());
    
    cout << ans[0] << '\n';
    for(int i=1; i<ans.size(); i++) {
        if(ans[i-1] == ans[i]) continue;
        cout << ans[i] << '\n';
    }
    
    return 0;
}
