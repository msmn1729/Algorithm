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

//https://www.acmicpc.net/problem/10798 세로읽기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    char s[5][20] = {};
    
    for(int i=0; i<5; i++)
    {
        cin >> s[i];
    }
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(s[j][i] != 0) cout << s[j][i];
        }
    }
    return 0;
}
