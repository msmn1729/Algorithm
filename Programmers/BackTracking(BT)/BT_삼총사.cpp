#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int n, ans;
int combi[15];
int check[15];
vector<int> g_number;

void dfs(int depth, int idx) {
    if(depth == 3) {
        int sum = 0;
        for(int i=0; i<3; i++) {
            sum += g_number[combi[i]];
        }
        if(sum == 0) ans++;
        return;
    }
    
    for(int i=idx; i<n; i++) {
        combi[depth] = i;
        dfs(depth+1, i+1);
    }
}

int solution(vector<int> number) {
    n = (int)number.size();
    g_number = number;
    dfs(0, 0);
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution({-2, 3, 0, 2, -5});
    
    return 0;
}
