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

using namespace std;

//https://www.acmicpc.net/problem/2023 신기한 소수

int n;

bool primeCheck(int num)
{
    if(num < 2) return false;
    for(int i=2; i*i<=num; i++)
    {
        if(num%i == 0) return false;
    }
    return true;
}

void dfs(int num, int depth)
{
    if(depth == n)
    {
        cout << num << '\n';
        return;
    }
    for(int i=1; i<=9; i+=2) //마지막 자리는 홀수
    {
        int tmp = num*10 + i;
        if(!primeCheck(tmp)) continue;
        dfs(tmp, depth+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int prime[4] = {2, 3, 5, 7}; //한자리 수 소수
    cin >> n;
    for(int i=0; i<4; i++)
    {
        dfs(prime[i], 1);
    }
    
    return 0;
}
