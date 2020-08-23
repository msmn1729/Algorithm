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

using namespace std;

//https://www.acmicpc.net/problem/7510 고급 수학

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long a, b, c;
    long long n, i=0;
    cin >> n;
    while(n--)
    {
        vector<long long> v;
        cin >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        
        cout << "Scenario #" << ++i << ":\n";
        if((v[0]*v[0] + v[1]*v[1]) == v[2]*v[2]) cout << "yes\n";
        else cout << "no\n";
        cout << '\n';
        v.clear();
    }
    
    return 0;
}
