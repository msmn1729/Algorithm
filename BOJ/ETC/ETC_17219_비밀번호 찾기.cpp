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

//https://www.acmicpc.net/problem/17219 비밀번호 찾기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    unordered_map<string, string> um;
    cin >> n >> m;
    while(n--) {
        string address, password;
        cin >> address >> password;
        um[address] = password;
    }
    while(m--) {
        string search;
        cin >> search;
        cout << um[search] << '\n';
    }
    
    return 0;
}
