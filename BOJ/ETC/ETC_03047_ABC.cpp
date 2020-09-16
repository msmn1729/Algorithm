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
#include <bitset>

using namespace std;

//https://www.acmicpc.net/problem/3047 ABC

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    for(int i=0; i<3; i++)
    {
        int in; cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    string s;
    cin >> s;
    for(int i=0; i<3; i++)
    {
        cout << v[s[i]-'A'] << ' ';
    }
    
    return 0;
}
