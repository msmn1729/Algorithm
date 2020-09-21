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
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/9625 BABBA

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[46] = {1};
    int b[46] = {};
    int i, n;
    cin >> n;
    for(i=1; i<=45; i++)
    {
        a[i] = b[i-1];
        b[i] = a[i-1] + b[i-1];
    }
    cout << a[n] << ' ' << b[n];

    return 0;
}
