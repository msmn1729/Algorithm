#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1062 가르침

int word[50];
int alpa;
int n, k, ans;

void go(int start, int depth) {
    if(depth == k) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if((alpa & word[i]) == word[i]) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i=start; i<26; i++) {
        if(alpa & (1 << i)) continue;
        alpa |= (1 << i);
        go(i+1, depth+1);
        alpa &= ~(1 << i);
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
    string str = "antic";
    for(char c : str) alpa |= 1 << (c - 'a');
    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(char c : s) word[i] |= 1 << (c - 'a');
    }
    go(0, 5); // 알파벳 5개 이상
    cout << ans;
    
    return 0;
}
