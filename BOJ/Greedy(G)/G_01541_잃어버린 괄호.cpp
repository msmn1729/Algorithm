#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1541 잃어버린 괄호

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    string num = "";
    int ans = 0;
    int sign = 1;
    s += '.';
    
    for(int i=0; i<s.size(); i++) {
        if(isdigit(s[i])) {
            num += s[i];
            continue;
        }
        ans += stoi(num) * sign;
        if(s[i] == '-') sign = -1;
        num = "";
    }
    cout << ans;
    
    return 0;
}
