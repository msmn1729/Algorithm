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

//https://www.acmicpc.net/problem/11728 배열 합치기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, i;
    int a[2000001] = {};
    cin >> n >> m;
    for(i=0; i<n+m; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n+m);
    for(i=0; i<n+m; i++)
    {
        cout << a[i] << ' ';
    }
    
    return 0;
}
