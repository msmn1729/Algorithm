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

using namespace std;

//https://www.acmicpc.net/problem/14910 오르막

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int prev = -2e9, cur;
    bool ans = true;
    
    while(!cin.eof())
    {
        cin >> cur;
        if(prev > cur) ans = false;
        prev = cur;
    }
    cout << (ans ? "Good" : "Bad");
    
    return 0;
}
