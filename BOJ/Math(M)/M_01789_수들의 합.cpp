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

//https://www.acmicpc.net/problem/1789 수들의 합

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll s, i, sum = 0;
    cin >> s;
    for(i=1; ; i++)
    {
        sum += i;
        if(sum > s) break;
    }
    cout << i-1;
    
    return 0;
}
