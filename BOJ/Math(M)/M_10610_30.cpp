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

//https://www.acmicpc.net/problem/10610 30

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    int sum = 0;
    for(char c : s)
    {
        sum += c-'0';
    }
    
    if(s.back() == '0' && sum%3 == 0) cout << s;
    else cout << -1;
    
    return 0;
}

