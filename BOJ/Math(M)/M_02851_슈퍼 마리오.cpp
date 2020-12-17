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

//https://www.acmicpc.net/problem/2851 슈퍼 마리오

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int in, sum = 0, ans = 0, prev = 0;
    for(int i=0; i<10; i++) {
        cin >> in;
        sum += in;
        if(abs(100-prev) > abs(100-sum)) ans = sum;
        else if(abs(100-prev) == abs(100-sum)) {
            ans = max(prev, sum);
        }
        prev = sum;
    }
    cout << ans;
    
    return 0;
}
