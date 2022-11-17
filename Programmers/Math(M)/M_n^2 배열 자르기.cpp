#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

vector<int> solution(int n, ll left, ll right) {
    vector<int> answer;
    
    for(ll i=left; i<=right; i++) {
        int row = i/n + 1;
        int col = i%n + 1;
        int num = max(row, col);
        answer.push_back(num);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution(3, 2, 5);

    return 0;
}
