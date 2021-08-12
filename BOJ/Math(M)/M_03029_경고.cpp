#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/3029 경고

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int h1, m1, s1, h2, m2, s2;
    char tmp;
    cin >> h1 >> tmp >> m1 >> tmp >> s1;
    cin >> h2 >> tmp >> m2 >> tmp >> s2;
    
    s1 += (h1 * 3600) + (m1 * 60);
    s2 += (h2 * 3600) + (m2 * 60);
    
    int dif = s2 - s1;
    if(dif <= 0) dif += 86400;
    
    printf("%02d:%02d:%02d", dif / 3600, dif % 3600 / 60, dif % 60);
    
    return 0;
}
