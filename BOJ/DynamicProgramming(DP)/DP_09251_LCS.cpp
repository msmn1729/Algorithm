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
#define INF 2e9

using namespace std;

//https://www.acmicpc.net/problem/9251 LCS

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[1002][1002] = {};
    string s1, s2, in;
    s1.push_back('\0');
    s2.push_back('\0');
    cin >> in;
    s1 += in;
    cin >> in;
    s2 += in;

    for(int i=1; i<s2.size(); i++) {
        for(int j=1; j<s1.size(); j++) {
            if(s1[j] == s2[i]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[s2.size()-1][s1.size()-1];
    
    return 0;
}
