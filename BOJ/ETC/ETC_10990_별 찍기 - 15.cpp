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

//https://www.acmicpc.net/problem/10990 별 찍기 - 15

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j;
    cin >> n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            cout << ' ';
        }
        cout << '*';
        for(j=0; j<2*i-1; j++)
        {
            cout << ' ';
        }
        if(i) cout << '*';
        cout << '\n';
    }
    
    return 0;
}
