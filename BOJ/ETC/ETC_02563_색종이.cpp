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

//https://www.acmicpc.net/problem/2563 색종이

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b;
    int ar[101][101] = {};
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                ar[a+i][b+j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(ar[i][j]) ans++;
        }
    }
    cout << ans;
    
    return 0;
}
