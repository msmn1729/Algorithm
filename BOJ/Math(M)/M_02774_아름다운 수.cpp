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

//https://www.acmicpc.net/problem/2774 아름다운 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        cout << s.size() << '\n';
    }

    return 0;
}

