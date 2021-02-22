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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/11478 서로 다른 부분 문자열의 개수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    unordered_set<string> str_set;
    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++) {
        string sub_str = "";
        for(int j=i; j<s.size(); j++) {
            sub_str += s[j];
        }
    }
    cout << str_set.size();
    
    return 0;
}
