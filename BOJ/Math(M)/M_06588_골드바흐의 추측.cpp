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

using namespace std;

//https://www.acmicpc.net/problem/6588 골드바흐의 추측
//에라토스테네스의 체!

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j;
    int prime[1000001] = {};
    
    for(i=2; i*i<=1000000; i++)
    {
        if(prime[i]) continue;
        for(j = i*i; j<=1000000; j+=i) prime[j] = 1;
    }

    while(1)
    {
        cin >> n;
        if(n == 0) break;
        for(i=3; i<=n/2;i++)
        {
            if(!prime[i] && !prime[n-i])
            {
                cout << n << " = " << i << " + " << n-i << '\n';
                break;
            }
        }
    }

    return 0;
}
