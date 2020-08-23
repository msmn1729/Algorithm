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

//https://www.acmicpc.net/problem/10093 숫자

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long s, e;
    cin >> s >> e;
    if(e < s) swap(s, e);
    if(s == e) cout << 0 << '\n';
    else cout << e-s-1 << '\n';
    while(s+1 < e)
    {
        cout << ++s << ' ';
    }
   
    return 0;
}
