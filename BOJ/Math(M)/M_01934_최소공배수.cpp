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

//https://www.acmicpc.net/problem/1934 최소공배수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        for(int i=a; i<=a*b; i+=a)
        {
            if(i%b == 0)
            {
                cout << i << '\n';
                break;
            }
        }
    }
    
    return 0;
}

