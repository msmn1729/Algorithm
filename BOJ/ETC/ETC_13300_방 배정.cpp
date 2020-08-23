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

//https://www.acmicpc.net/problem/13300 방 배정

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k, i, s, y;
    int x[7][2] = {};
    cin >> n >> k;
    for(i=0; i<n; i++)
    {
        cin >> s >> y;
        x[y][s]++;
    }
    int ans=0;
    for(i=1; i<=6; i++)
    {
        for(int j=0; j<2; j++)
        {
            ans += (x[i][j]+k-1)/k;
        }
    }
    cout << ans;
    return 0;
}
