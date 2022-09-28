#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

int solution(vector<int> A) {
    vector<int> prefixSum(A.size());
    prefixSum[0] = A[0];
    int ans = 2e9;
    
    for(int i=1; i<prefixSum.size(); i++) {
        prefixSum[i] = prefixSum[i-1] + A[i];
    }
    
    for(int i=1; i<prefixSum.size(); i++) {
        ans = min(ans, abs(prefixSum[i-1] - (prefixSum.back() - prefixSum[i-1])));
    }
    
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cout << solution({3, 1, 2, 4, 3}) << '\n';
    cout << solution({0, 1, 5, 7});
    
    return 0;
}
