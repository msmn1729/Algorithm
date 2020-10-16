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

using namespace std;

//https://www.acmicpc.net/problem/4447 좋은놈 나쁜놈

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        string s;
        getline(cin, s);
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'g' || s[i] == 'G') cnt1++;
            else if(s[i] == 'b' || s[i] == 'B') cnt2++;
        }
        cout << s << " is ";
        if(cnt1 > cnt2) cout << "GOOD\n";
        else if(cnt1 < cnt2) cout << "A BADDY\n";
        else cout << "NEUTRAL\n";
    }
    
    return 0;
}
