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

//https://www.acmicpc.net/problem/11655 ROT13

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    getline(cin, s);
    
    for(char c : s)
    {
        if('a' <= c && c <= 'z') cout << char('a' + (c - 'a' + 13) % 26);
        else if('A' <= c && c <= 'Z') cout << char('A' + (c - 'A' + 13) % 26);
        else cout << c;
    }
    
    return 0;
}
