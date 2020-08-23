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

//https://www.acmicpc.net/problem/2443 별 찍기 - 6

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
        for(j=0; j<i; j++)
        {
            cout << ' ';
        }
        for(j=0; j < n*2-i*2-1; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
    
    return 0;
}
