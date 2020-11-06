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

//https://www.acmicpc.net/problem/5052 전화번호 목록

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        string s[10001] = {};
        for(int i=0; i<n; i++)
        {
            cin >> s[i];
        }
        sort(s, s+n);
        
        bool flag = false;
        for(int i=1; i<n; i++)
        {
            if(0 == s[i].find(s[i-1]))
            {
                flag = true;
                break;
            }
        }
        if(flag) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }
    
    return 0;
}
