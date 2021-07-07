#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, bomb, ans;
    cin >> s >> bomb;
    
    for(int i=0; i<s.size(); i++) {
        ans.push_back(s[i]);
        if(ans.back() == bomb.back()) {
            int cnt = 0;
            for(int j=0; j<bomb.size(); j++) {
                if(ans[ans.size()-1-j] == bomb[bomb.size()-1-j]) cnt++;
                else break;
            }
            if(cnt == bomb.size()) ans.erase(ans.size()-cnt, cnt);
        }
    }
    if(ans.empty()) cout << "FRULA";
    else cout << ans;
    
    return 0;
}
