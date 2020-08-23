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

//https://www.acmicpc.net/problem/2966 찍기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j, x[3][1001]={};
    string s;
    cin >> n;
    cin >> s;
    
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==0)
            {
                x[i][j] = j%3;
            }
            else if(i==1)
            {
                x[i][j] = 1;
                x[i][j+1] = 0;
                x[i][j+2] = 1;
                x[i][j+3] = 2;
                j+=3;
            }
            else if(i==2)
            {
                x[i][j] = 2;
                x[i][j+1] = 2;
                x[i][j+2] = 0;
                x[i][j+3] = 0;
                x[i][j+4] = 1;
                x[i][j+5] = 1;
                j+=5;
            }
        }
    }
    vector<pair<int, string> > v;
    int cnt1=0, cnt2=0, cnt3=0, mx;
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {
            if(x[i][j]+'A' == s[j] && i == 0) cnt1++;
            else if(x[i][j]+'A' == s[j] && i == 1) cnt2++;
            else if(x[i][j]+'A' == s[j] && i == 2) cnt3++;
        }
    }
    int ans = 1;
    mx = cnt1;
    if(cnt1 < cnt2)
    {
        ans = 2;
        mx = cnt2;
    }
    if(mx < cnt3)
    {
        ans = 3;
        mx = cnt3;
    }
    cout << mx << '\n';
    
    v.push_back({cnt1, "Adrian"});
    v.push_back({cnt2, "Bruno"});
    v.push_back({cnt3, "Goran"});
    sort(v.begin(), v.end());
    
    for(auto i: v)
    {
        if(i.first == mx) cout << i.second << '\n';
    }
    
    return 0;
}
