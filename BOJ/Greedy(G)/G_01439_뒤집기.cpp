#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, uni_s = "";
    cin >> s;

    int zero_cnt = 0, one_cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(uni_s.back() == s[i]) continue;
        uni_s += s[i];
        if(s[i] == '0') zero_cnt++;
        else one_cnt++;
    }
    
    cout << min(zero_cnt, one_cnt);
    
    return 0;
}
