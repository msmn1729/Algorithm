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

//https://www.acmicpc.net/problem/1620 나는야 포켓몬 마스터 이다솜

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<int, string> ismap;
    map<string, int> simap;
    int n, m, i;
    cin >> n >> m;
    
    for(i=1; i<=n; i++) {
        string s;
        cin >> s;
        ismap[i] = s;
        simap[s] = i;
    }
    while(m--) {
        string s;
        cin >> s;
        
        if(isdigit(s[0])) {
            cout << ismap[stoi(s)] << '\n';
        }
        else {
            cout << simap[s] << '\n';
        }
    }
    
    return 0;
}
