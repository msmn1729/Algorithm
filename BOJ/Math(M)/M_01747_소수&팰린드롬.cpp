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

//https://www.acmicpc.net/problem/1747 소수&팰린드롬

bool PalindromeCheck(int n)
{
    int ten = 1;
    string s = "";
    while(n)
    {
        s += (n%10 + '0');
        n /= 10;
        ten *= 10;
    }
    string s2 = s;
    reverse(s.begin(), s.end());
    if(s == s2) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j, n;
    int max_num = 2e6;
    vector<bool> prime(max_num+1);
    prime[1] = 1;
    
    cin >> n;
    
    for(i=2; i<=max_num; i++)
    {
        if(prime[i]) continue;
        prime.push_back(i);
        if(i*i > max_num) continue;
        for(j=i+i; j<=max_num; j+=i) prime[j] = 1;
    }
    
    for(i=n; i<=max_num; i++)
    {
        if(!prime[i] && PalindromeCheck(i))
        {
            cout << i;
            break;
        }
    }
    
    return 0;
}
