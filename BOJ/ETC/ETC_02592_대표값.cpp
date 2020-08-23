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

//https://www.acmicpc.net/problem/2592 대표값

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x[101]={};
    int i, in, sum=0;
    for(i=0; i<10; i++)
    {
        cin >> in;
        x[in/10]++;
        sum += in;
    }
    int ans=0;
    for(i=1; i<=100; i++)
    {
        if(x[ans] < x[i]) ans = i;
    }
    cout << sum/10 << '\n' << ans*10;
   
    return 0;
}
