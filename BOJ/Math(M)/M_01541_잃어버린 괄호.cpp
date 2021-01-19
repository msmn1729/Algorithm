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
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/1541 잃어버린 괄호

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int sum = 0;
    int sign = 1;
    vector<pair<int, int> > v;
    
    for(int i=0; i<s.size(); i++) {

        if(isdigit(s[i])) {
            sum += (s[i]-'0');
            sum *= 10;
        }
        if(!isdigit(s[i]) || i == s.size()-1) {
            sum /= 10;
            v.push_back({sum, sign});
            sum = 0;
        }
        if(s[i] == '-') sign = -1;
        else if(s[i] == '+') sign = 1;
    }
    
    int ans = 0;
    bool flag = false;
    for(auto& it : v) {
        if(flag) it.second = -1;
        if(it.second == -1) flag = true;
    }
    for(auto it : v) {
        ans += it.first * it.second;
    }
    cout << ans;
    
    return 0;
}
