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

//https://www.acmicpc.net/problem/2352 반도체 설계

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, a;
    vector<int> dp(1); // dp[a] : 길이가 a인 LIS들의 마지막 숫자의 최솟값
    cin >> n;
    
    while(n--) {
        cin >> a;
        if(dp.back() < a) dp.push_back(a);
        else *lower_bound(dp.begin(), dp.end(), a) = a;
    }
    cout << dp.size() - 1;

    return 0;
}
