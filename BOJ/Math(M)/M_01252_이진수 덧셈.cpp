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

//https://www.acmicpc.net/problem/1252 이진수 덧셈

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b, ans = "";
    cin >> a >> b;
    
    int carry = 0;
    bool flag = false;
    while(a.size() || b.size() || carry) {
        int sum = 0;
        if(a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        if(sum) flag = true;
        ans += (sum+carry)%2 + '0';
        carry = (sum+carry)/2;
    }
    if(flag == false) {
        cout << '0';
        return 0;
    }
    while(ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}

