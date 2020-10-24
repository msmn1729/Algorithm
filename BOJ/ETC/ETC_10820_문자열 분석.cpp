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

//https://www.acmicpc.net/problem/10820 문자열 분석

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    while(getline(cin, s))
    {
        int small, big, num, white;
        small=big=num=white=0;
        for(char c : s)
        {
            if('a'<=c&&c<='z') small++;
            else if('A'<=c&&c<='Z') big++;
            else if(isdigit(c)) num++;
            else if(c == ' ') white++;
        }
        cout << small << ' ' << big << ' ' << num << ' ' << white << '\n';
    }
    
    return 0;
}

