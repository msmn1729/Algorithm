#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1759 암호 만들기

int l, c;
char alpa[20];
char combi[20];

int IsVowel(char c) {
    string word = "aeiou";
    if(find(word.begin(), word.end(), c) == word.end()) return 0;
    return 1;
}

void go(int start, int depth, int cnt1, int cnt2) {
    if(depth == l) {
        if(cnt1 >= 1 && cnt2 >= 2) cout << combi << '\n'; // 모음, 자음 개수 충족시 출력
        return;
    }
    
    for(int i=start; i<c; i++) {
        combi[depth] = alpa[i];
        if(IsVowel(alpa[i])) go(i+1, depth+1, cnt1+1, cnt2);
        else go(i+1, depth+1, cnt1, cnt2+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> l >> c;
    for(int i=0; i<c; i++) cin >> alpa[i];
    sort(alpa, alpa+c);
    go(0, 0, 0, 0);
    
    return 0;
}
