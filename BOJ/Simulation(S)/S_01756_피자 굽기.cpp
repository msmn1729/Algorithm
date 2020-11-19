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

//https://www.acmicpc.net/problem/1756 피자 굽기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int d, n, i;
    int oven[300000] = {}, pizza[300000] = {};
    cin >> d >> n;
    
    for(i=0; i<d; i++)
    {
        cin >> oven[i];
        if(i) oven[i] = min(oven[i-1], oven[i]);
    }
    
    for(i=0; i<n; i++) cin >> pizza[i];

    int cnt = 0;
    for(i=d-1; i>=0; i--)
    {
        if(pizza[cnt] <= oven[i]) cnt++;

        if(cnt == n)
        {
            cout << i+1;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
