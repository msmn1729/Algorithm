#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1062 가르침

int ar[51][30] = {};
int alpa[30];
int n, k, ans;

void go(int start, int depth) {
    if(depth == k-5) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            int flag = 0;
            for(int j=0; j<26; j++) {
                if(ar[i][j] == 1 && alpa[j] == 0) {
                    flag = 1;
                }
            }
            if(!flag) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i=start; i<26; i++) {
        if(alpa[i]) continue;
        alpa[i] = 1;
        go(i+1, depth+1);
        alpa[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    if(k < 5) {
        cout << 0;
        return 0;
    }
    if(k == 26) {
        cout << n;
        return 0;
    }
    string word = "antic";
    for(char c : word) alpa[c - 'a'] = 1;
        
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        s = s.substr(4, s.size()-8);
        for(char c : s) ar[i][c - 'a'] = 1;
    }
    go(0, 0);
    cout << ans;
    
    return 0;
}
