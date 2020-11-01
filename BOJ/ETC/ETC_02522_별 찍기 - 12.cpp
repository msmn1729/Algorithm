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

//https://www.acmicpc.net/problem/2522 별 찍기 - 12

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i, j;
    cin >> n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++) cout << ' ';
        for(j=0; j<=i; j++) cout << '*';
        cout << '\n';
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<=i; j++) cout << ' ';
        for(j=0; j<n-i-1; j++) cout << '*';
        cout << '\n';
    }
    
    return 0;
}
