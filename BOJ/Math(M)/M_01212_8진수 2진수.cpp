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

//https://www.acmicpc.net/problem/1212 8진수 2진수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    if(s == "0") cout << 0;
    for(int i=0; i<s.size(); i++) {
        int n = s[i]-'0', cnt = 0;
        string tmp = "";
        while(n) {
            if(n%2) tmp += '1';
            else tmp += '0';
            n/=2;
            cnt++;
        }
        for(int j=0; i && j<3-cnt; j++) {
            tmp += '0';
        }
        cnt = 0;
        reverse(tmp.begin(), tmp.end());
        cout << tmp;
    }
    
    return 0;
}
