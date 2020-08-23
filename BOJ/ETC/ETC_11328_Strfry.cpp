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

//https://www.acmicpc.net/problem/11328 Strfry

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i;
    cin >> n;
    string s1, s2;
    while(n--)
    {
        int alpa[26]={};
        cin >> s1 >> s2;
        for(char x : s1) alpa[x - 'a']++;
        for(char x : s2) alpa[x - 'a']--;
        for(i=0; i<26; i++)
        {
            if(alpa[i]) break;
        }
        cout << (i==26 ? "Possible" : "Impossible") << '\n';
    }
    
    return 0;
}
