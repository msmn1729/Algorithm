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
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2407 조합

string strSum(string s1, string s2) {
    string ret = "";
    int sum = 0;
    while(s1.size() || s2.size() || sum) {
        if(s1.size()) {
            sum += s1.back() - '0';
            s1.pop_back();
        }
        if(s2.size()) {
            sum += s2.back() - '0';
            s2.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string dp[101][101] = {};
    for(int i=0; i<=100; i++) dp[i][0] = '1';
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] =  strSum(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    int n, m;
    cin >> n >> m;
    cout << dp[n][m];
    
    return 0;
}
