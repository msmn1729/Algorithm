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

//https://www.acmicpc.net/problem/4470 줄번호

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, cnt = 0;
    cin >> n;
    string s;
    getline(cin, s);
    while(n--)
    {
        getline(cin, s);
        cout << ++cnt << ". " << s << '\n';
    }
    
    return 0;
}

