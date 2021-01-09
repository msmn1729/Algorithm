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

//https://www.acmicpc.net/problem/11723 집합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //배열을 이용한 풀이
    int n;
    int ar[21] = {};

    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int in;

        if(s == "add") {
            cin >> in;
            ar[in] = 1;
        }
        else if(s == "remove") {
            cin >> in;
            ar[in] = 0;
        }
        else if(s == "check") {
            cin >> in;
            if(ar[in]) cout << 1;
            else cout << 0;
            cout << '\n';
        }
        else if(s == "toggle") {
            cin >> in;
            if(ar[in]) ar[in] = 0;
            else ar[in] = 1;
        }
        else if(s == "all") {
            fill(ar, ar+sizeof(ar)/sizeof(int), 1);
        }
        else if(s == "empty") {
            fill(ar, ar+sizeof(ar)/sizeof(int), 0);
        }
    }
    
    return 0;
}
