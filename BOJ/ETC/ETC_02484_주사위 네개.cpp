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

using namespace std;

//https://www.acmicpc.net/problem/2484 주사위 네개

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j, mx, ans=0, mx_ans=0;
    cin >> n;
    while(n--)
    {
        mx = 0;
        int x[7]={}, in;
        for(i=0; i<4; i++)
        {
            cin >> in;
            mx = max(mx, in);
            x[in]++;
        }
        for(i=1; i<=6; i++)
        {
            if(x[i] == 4)
            {
                ans = 50000+(i*5000);
                break;
            }
            else if(x[i] == 3)
            {
                ans = 10000+(i*1000);
                break;
            }
            else if(x[i] == 2)
            {
                for(j=i+1; j<=6; j++)
                {
                    if(x[j] == 2)
                    {
                        ans = 2000+(j*500 + i*500);
                        break;
                    }
                }
                if(j == 7)
                {
                    ans = 1000+i*100;
                    break;
                }
                break;
            }
        }
        if(i == 7)
        {
            ans = mx*100;
        }
        mx_ans = max(mx_ans, ans);
    }
    cout << mx_ans;
    
    return 0;
}
