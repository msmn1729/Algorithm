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

//https://www.acmicpc.net/problem/2506 점수계산

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, sum = 0, ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int in;
        cin >> in;
        if(in) sum++;
        else sum = 0;
        ans += sum;
    }
    cout << ans;
    
    return 0;
}
