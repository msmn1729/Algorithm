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

//https://www.acmicpc.net/problem/9184 신나는 함수 실행

int dp[21][21][21];

int solution(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return solution(20, 20, 20);
    
    int &ret = dp[a][b][c];
    if(ret) return dp[a][b][c];
    
    if(a<b && b<c) return ret = solution(a, b, c-1) + solution(a, b-1, c-1)
        - solution(a, b-1, c);
    
    return ret = solution(a-1, b, c) + solution(a-1, b-1, c)
        + solution(a-1, b, c-1) - solution(a-1, b-1, c-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c;
    while(1) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, solution(a, b, c));
    }
    
    return 0;
}
