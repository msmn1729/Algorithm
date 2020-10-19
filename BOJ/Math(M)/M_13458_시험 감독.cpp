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

//https://www.acmicpc.net/problem/13458 시험 감독

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int b, c;
    vector<int> v;
    cin >> n;
    while(n--)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    cin >> b >> c;
    ll ans = 0;
    for(int it : v)
    {
        it -= b;
        ans++;
        if(it<=0)
        {
            continue;
        }
        ans += ((it-1)/c)+1;
        
    }
    cout << ans << '\n';
    
    return 0;
}
