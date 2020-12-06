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

//https://www.acmicpc.net/problem/3058 짝수를 찾아라

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    while(n--) {
        int mn = 2e9, sum = 0;
        for(int i=0; i<7; i++) {
            int tmp;
            cin >> tmp;
            if(tmp%2) continue;
            sum += tmp;
            mn = min(mn, tmp);
        }
        cout << sum << ' ' << mn << '\n';
    }
    return 0;
}
