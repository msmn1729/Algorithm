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

//https://www.acmicpc.net/problem/10102 개표

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, cnt=0, cnt2=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'A') cnt++;
        else if(s[i] == 'B') cnt2++;
    }
    if(cnt > cnt2) puts("A");
    else if(cnt < cnt2) puts("B");
    else puts("Tie");
    
    return 0;
}

