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
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/5557 1학년

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j, in, sum = 0;
    vector<int> v;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> in;
        v.push_back(in);
    }
    sum = v.back();
    v.pop_back();
    
    ll dp[100][21] = {}; //인덱스 0~98를 사용, 연산 값 0~20
    dp[0][v[0]] = 1;
    for(i=1; i<v.size(); i++) //1부터 시작
    {
        for(j=0; j<=20; j++)
        {
            if(j + v[i] <= 20) dp[i][j+v[i]] += dp[i-1][j];
            if(j - v[i] >= 0) dp[i][j-v[i]] += dp[i-1][j];
        }
    }
    cout << dp[v.size()-1][sum]; //인덱스이므로 -1
    
    return 0;
}
