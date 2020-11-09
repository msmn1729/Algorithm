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

//https://www.acmicpc.net/problem/5525 IOIOI

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, len;
    int p_cnt = 0;
    int ans = 0;
    
    string s;
    cin >> n >> len;
    cin >> s;
    
    for(int i=1; i<len-1; i++)
    {
        if(s[i-1] == 'I' && s[i] == 'O' && s[i+1] == 'I')
        {
            p_cnt++;
            i++;
        }
        else p_cnt = 0;
        if(p_cnt == n)
        {
            ans++;
            p_cnt--;
        }
    }
    cout << ans;
    
    return 0;
}
