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

//https://www.acmicpc.net/problem/10807 개수 세기

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int in, n, x[201]={};
    cin >> n;
    while(n--)
    {
        cin >> in;
        x[in+100]++;
    }
    cin >> n;
    cout << x[n+100];
    
    return 0;
}
