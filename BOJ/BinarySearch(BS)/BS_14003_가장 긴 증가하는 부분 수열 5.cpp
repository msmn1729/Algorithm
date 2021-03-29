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

//https://www.acmicpc.net/problem/14003 가장 긴 증가하는 부분 수열 5

int ar[1000005];
int LIS[1000005];
vector<int> dp(1, -INF-1); //dp[a]: 길이가 a인 LIS 중 마지막 숫자의 최솟값

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
        if(dp.back() < ar[i]) {
            dp.push_back(ar[i]);
            int idx = (int)dp.size() - 1; //윗줄이랑 바뀌면 사이즈 변함
            LIS[i] = idx;
        }
        else {
            int idx = (int)(lower_bound(dp.begin(), dp.end(), ar[i]) - dp.begin());
            dp[idx] = ar[i];
            LIS[i] = idx;
        }
    }
    int LIS_len = (int)dp.size() - 1;
    cout << LIS_len << '\n';
    
    vector<int> ans;
    for(int i=n; i>=1; i--) {
        if(LIS_len == LIS[i]) {
            ans.push_back(ar[i]);
            LIS_len--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    for(int it: ans) cout << it << ' ';
    
    return 0;
}
