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

//https://www.acmicpc.net/problem/1919 애너그램 만들기

int chk(string s1, string s2)
{
    int cnt[26]={}, i, ans=0;
    for(char c: s1) cnt[c - 'a']++;
    for(char c: s2) cnt[c - 'a']--;
    for(i=0; i<26; i++) ans += abs(cnt[i]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s1, s2, t_s1, t_s2;
    cin >> s1 >> s2;
    cout << chk(s1, s2);
    
    return 0;
}
