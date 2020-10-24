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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/2167 2차원 배열의 합

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ar[301][301] = {};
    int i, j;
    int r, c;
    cin >> r >> c;
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            cin >> ar[i][j];
        }
    }
    
    int n;
    cin >> n;
    while(n--)
    {
        int sum = 0;
        int st_x, st_y, ed_x, ed_y;
        cin >> st_x >> st_y >> ed_x >> ed_y;
        for(i=st_x; i<=ed_x; i++)
        {
            for(j=st_y; j<=ed_y; j++)
            {
                sum += ar[i][j];
            }
        }
        cout << sum << '\n';
    }
    
    return 0;
}

