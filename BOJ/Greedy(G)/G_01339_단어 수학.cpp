#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1339 단어 수학
// 그리디 풀이
// 백트래킹도 모든 조합을 따져보면 10!이므로 가능하지만 효율이 떨어짐
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    int weight[30] = {};
    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int ten = 1;
        for(char c : s) {
            weight[c - 'A'] += ten;
            ten *= 10;
        }
    }
    sort(weight, weight+26, greater<>());
    int ans = 0;
    int num = 9;
    for(int i=0; i<26; i++) {
        if(weight[i] == 0) break;
        ans += weight[i] * num--;
    }
    cout << ans;

    return 0;
}
