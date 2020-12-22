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

//https://www.acmicpc.net/problem/3059 등장하지 않는 문자의 합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while(n--) {
        int alpa[26] = {};
        string s;
        int sum = 0;
        cin >> s;
        for(auto it : s) {
            alpa[it-'A']++;
        }
        for(int i=0; i<26; i++) {
            if(alpa[i]) continue;
            sum += i+65;
        }
        cout << sum << '\n';
    }
    
    return 0;
}

