#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1213 팰린드롬 만들기

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int alpa[30] = {};
    string s;
    cin >> s;
    
    for(int i=0; i<s.size(); i++) alpa[s[i] - 'A']++;

    int cnt = 0;
    char target = '\0';
    for(int i=0; i<=26; i++) {
        if(alpa[i] % 2) {
            cnt++;
            target = i + 'A';
        }
    }
    
    // 알파벳의 개수가 홀수인 알파벳이 2개 이상이면 불가
    if(cnt >= 2) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    // 가능한 경우
    string ans = "";
    for(int i=0; i<=26; i++) {
        for(int j=0; j<alpa[i]/2; j++) {
            ans += 'A' + i;
        }
    }
    int sz = (int)ans.size();
    
    // 중간에 하나짜리 알파벳을 넣는 경우
    if(cnt == 1) ans += target;
    
    for(int i=sz-1; i>=0; i--) {
        ans += ans[i];
    }
    cout << ans;
    
    return 0;
}
