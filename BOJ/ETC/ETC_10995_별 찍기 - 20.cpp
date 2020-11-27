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

//https://www.acmicpc.net/problem/10995 별 찍기 - 20

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n*2; j++)
        {
            if((i+j)%2) cout << ' ';
            else cout << "*";
        }
        cout << '\n';
    }
    
    return 0;
}
