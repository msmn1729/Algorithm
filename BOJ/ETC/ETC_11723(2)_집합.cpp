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

//https://www.acmicpc.net/problem/11723 집합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //비트마스킹을 이용한 풀이
    int n;
    int bit = 0;

    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int in;

        if(s == "add") {
            cin >> in;
            bit |= (1 << in);
        }
        else if(s == "remove") {
            cin >> in;
            bit &= ~(1 << in);
        }
        else if(s == "check") {
            cin >> in;
            if(bit & (1 << in)) cout << 1;
            else cout << 0;
            cout << '\n';
        }
        else if(s == "toggle") {
            cin >> in;
            bit ^= (1 << in);
        }
        else if(s == "all") {
            bit = (1 << 21) - 1;
        }
        else if(s == "empty") {
            bit = 0;
        }
    }
    
    return 0;
}
