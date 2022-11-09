#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str, s = "";
    getline(cin, str);
    
    int flag = 0;
    for(char c : str) {
        if(c != ' ') flag = 1;
        if(flag) s += c;
    }
    
    if(s.empty()) {
        cout << 0;
        return 0;
    }
    int ans = 1;
    int size = (int)s.size()-1;
    for(int i=0; i<size; i++) {
        if(s[i] == ' ' && s[i+1] != ' ') ans++;
    }
    cout << ans;
    
    return 0;
}
