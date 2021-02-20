#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/10824 네 수

string strSum(string a, string b) {
    int sum = 0;
    string result = "";
    while(a.size() || b.size() || sum) {
        if(a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        result += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << strSum(a + b, c + d);
    
    return 0;
}
