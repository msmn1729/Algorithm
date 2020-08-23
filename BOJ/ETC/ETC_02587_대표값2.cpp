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

//https://www.acmicpc.net/problem/2587 대표값2

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x[101]={};
    int i, in, sum=0;
    for(i=0; i<5; i++)
    {
        cin >> in;
        x[i] = in;
        sum += in;
    }
    sort(x, x+5);
    cout << sum/5 << '\n' << x[2];
   
    return 0;
}
