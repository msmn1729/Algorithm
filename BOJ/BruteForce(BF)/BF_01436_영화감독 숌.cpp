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

//https://www.acmicpc.net/problem/1436 영화감독 숌

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int six_num = 666;
    int n, cnt = 0;
    cin >> n;
    string s;
    
    while(1) {
        s = to_string(six_num++);
        if(s.find("666") != -1) cnt++;
        if(cnt == n) {
            cout << s;
            break;
        }
    }
    
    return 0;
}
