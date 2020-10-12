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

using namespace std;

//https://www.acmicpc.net/problem/10419 지각

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    int dp[10001] = {};
    for(int i=1; i<=10000; i++) dp[i] = i*i;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int in;
        cin >> in;
        for(int j=1; j*j<=10000; j++)
        {
            if(j + j*j > in)
            {
                cout << j-1 << '\n';
                break;
            }
        }
    }

    return 0;
}

