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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/5217 쌍의 합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i;
    cin >> n;
    while(n--) {
        int in;
        cin >> in;
        cout << "Pairs for " << in << ':';
        int flag = 0;
        for(i=1; i<=in/2; i++) {
            if(i != in-i) {
                if(flag) {
                    cout << ',';
                }
                cout << ' ' << i << ' ' << in-i;
                flag = 1;
            }
        }
        cout << '\n';
    }
    
    return 0;
}
