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

//https://www.acmicpc.net/problem/10886 0 = not cute / 1 = cute

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, cnt0 = 0, cnt1 = 0;
    cin >> n;
    while(n--) {
        int in;
        cin >> in;
        if(in) cnt1++;
        else cnt0++;
    }
    if(cnt1>cnt0) cout << "Junhee is cute!";
    else cout << "Junhee is not cute!";
    return 0;
}
