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

//https://www.acmicpc.net/problem/2455 지능형 기차

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int prev_a, prev_b, prev_sum, sum = 0, ans = -2e9;
    cin >> prev_a >> prev_b;
    prev_sum = prev_b - prev_a;
    
    for(int i=0; i<3; i++)
    {
        int a, b;
        cin >> a >> b;
        sum = b - a + prev_sum;
        ans = max(ans, sum);
        prev_sum = sum;
    }
    cout << ans;
    
    return 0;
}
