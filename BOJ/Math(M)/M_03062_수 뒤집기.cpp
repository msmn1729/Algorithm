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

//https://www.acmicpc.net/problem/3062 수 뒤집기

string strSum(string s1, string s2) {
    int sum = 0;
    string result = "";
    
    while(s1.size() || s2.size() || sum) {
        if(s1.size()) {
            sum += s1.back() - '0';
            s1.pop_back();
        }
        if(s2.size()) {
            sum += s2.back() - '0';
            s2.pop_back();
        }
        result += sum%10 + '0';
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while(t--) {
        string s = "", rs = "";
        cin >> s;
        rs = s;
        reverse(rs.begin(), rs.end());

        string sum = strSum(s, rs);
        string rsum = sum;
        reverse(rsum.begin(), rsum.end());
        
        if(sum == rsum) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    
    return 0;
}

