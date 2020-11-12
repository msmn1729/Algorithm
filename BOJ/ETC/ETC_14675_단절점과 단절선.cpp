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

//https://www.acmicpc.net/problem/14675 단절점과 단절선

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i;
    int ar[100001] = {};
    
    cin >> n;
    int a, b;
    for(i=0; i<2*(n-1); i++)
    {
        cin >> a;
        ar[a]++;
    }
    
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        if(a == 1)
        {
            if(ar[b] == 1) cout << "no\n";
            else cout << "yes\n";
        }
        else if(a == 2)
        {
            cout << "yes\n";
        }
    }
    
    return 0;
}
