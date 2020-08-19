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
#include <cstdlib>
#include <cmath>

using namespace std;

//https://www.acmicpc.net/problem/2003 수들의 합2 실버3

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, in;
    vector<int> v;
    
    cin >> n >> m;
    while(n--)
    {
        cin >> in;
        v.push_back(in);
    }
    
    //투 포인터
    int start=0, end=0, sum=0, ans=0;
    while(end <= v.size())
    {
        if(sum < m) //부분합이 더 작을 때
        {
            sum += v[end++];
        }
        else if(sum >= m) //부분합이 더 크거나 같을 때
        {
            sum -= v[start++];
        }
        if(sum == m)
        {
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}
