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

//https://www.acmicpc.net/problem/2444 별 찍기 - 7

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j, n;
    cin >> n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            cout << ' ';
        }
        for(j=0; j < i*2+1; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<=i; j++)
        {
            cout << ' ';
        }
        for(j=0; j < 2*n - 2*i - 3; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
    
    return 0;
}
