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

string solution(int n)
{
    string s[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    string ans = "";
    vector<int> v;
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(), v.end());
    for(int it : v)
    {
        ans += s[it];
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution(147);
    
    return 0;
}
