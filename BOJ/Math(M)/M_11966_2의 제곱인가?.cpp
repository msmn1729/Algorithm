#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/11966 2의 제곱인가?

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while(n > 1)
    {
        if(n%2)
        {
            cout << 0;
            return 0;
        }
        n /= 2;
    }
    cout << 1;
    
    return 0;
}
