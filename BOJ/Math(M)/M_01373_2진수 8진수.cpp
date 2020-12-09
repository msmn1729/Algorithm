#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/1373 2진수 8진수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, bi_num = "";
    cin >> s;
    int tmp = s.size() % 3;
    if(tmp == 1) tmp = 2;
    else if(tmp == 2) tmp = 1;
    
    int ans = 0, two = 1;
    for(int i=0; i<s.size(); i++) {
        bi_num.push_back(s[i]);
        
        if((tmp+i+1)%3 == 0) {
            while(bi_num.size()) {
                ans += (bi_num.back() - '0') * two;
                two *= 2;
                bi_num.pop_back();
            }
            cout << ans;
            ans = 0;
            two = 1;
        }
    }
    
    
    return 0;
}
