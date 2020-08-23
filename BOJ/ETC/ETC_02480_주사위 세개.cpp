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

//https://www.acmicpc.net/problem/2480 주사위 세개

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x[10]={};
    int mx = -1;
    for(int i=0; i<3; i++)
    {
        int in;
        cin >> in;
        mx = max(mx, in);
        x[in]++;
    }
    int sum=0;
    for(int i=1; i<=6; i++)
    {
        if(x[i] == 3)
        {
            sum = 10000+(i*1000);
            cout << sum;
            return 0;
        }
        else if(x[i] == 2)
        {
            sum = 1000+(i*100);
            cout << sum;
            return 0;
        }
    }
    cout << mx*100;
    
   
    return 0;
}
