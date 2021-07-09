#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1339 단어 수학
// 백트래킹 풀이
// 조합의 수 10!이므로 가능

int alpa_num[30];
int visited[10];
int ans;
vector<string> info;
vector<char> alpa;

void go(int depth) {
    if(depth == alpa.size()) {
        int sum = 0;
        for(string s : info) {
            int num = 0;
            if(alpa_num[s[0]] == '0') continue; // 첫 글자가 0인 경우 패스
            for(char c : s) {
                num *= 10;
                num += alpa_num[c-'A'];
            }
            sum += num;
        }
        ans = max(ans, sum);
        return;
    }
    
    for(int i=0; i<=9; i++) {
        if(visited[i]) continue; // 사용한 숫자 패스
        int idx = alpa[depth] - 'A';
        
        visited[i] = 1;
        alpa_num[idx] = i;
        go(depth+1);
        visited[i] = 0;
        alpa_num[idx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    memset(alpa_num, -1, sizeof(alpa_num));
    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        info.push_back(s);
        for(char c : s) {
            if(find(alpa.begin(), alpa.end(), c) != alpa.end()) continue;
            alpa.push_back(c); // 중복제거된 알파벳 삽입
        }
    }
    go(0);
    cout << ans;
   
    return 0;
}
