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

//https://www.acmicpc.net/problem/20299 3대 측정

struct info
{
    int a, b, c;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k, l;
    vector<info> v;
    cin >> n >> k >> l;
    
    while(n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a+b+c >= k)
            if(a >= l && b >= l && c >= l)
                v.push_back({a, b, c});
    }
    cout << v.size() << '\n';
    for(auto it : v) cout << it.a << ' ' << it.b << ' ' << it.c << ' ';
    
    return 0;
}
