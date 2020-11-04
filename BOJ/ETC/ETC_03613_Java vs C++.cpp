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

//https://www.acmicpc.net/problem/3613 Java vs C++

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int jflag = 1, cflag = 1;
    int err_flag = 0;
    
    if(('A' <= s.front() && s.front() <= 'Z') || s.front() == '_' || s.back() == '_')
    {
        err_flag = 1;
    }
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '_')
        {
            if(s[i+1] == '_') err_flag = 1;
            jflag = 0;
        }
        else if('A' <= s[i] && s[i] <= 'Z') cflag = 0;
    }
    
    string ans = "";
    if(jflag)
    {
        for(int i=0; i<s.size(); i++)
        {
            if('A' <= s[i] && s[i] <= 'Z')
            {
                ans += '_';
                s[i] += 'a' - 'A';
            }
            ans += s[i];
        }
    }
    else if(cflag)
    {
        int underbar_flag = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '_')
            {
                underbar_flag = 1;
                continue;
            }
            if(underbar_flag)
            {
                s[i] += 'A' - 'a';
                underbar_flag = 0;
            }
            ans += s[i];
        }
    }
    else err_flag = 1;
    
    if(err_flag) cout << "Error!";
    else cout << ans;
    
    return 0;
}
