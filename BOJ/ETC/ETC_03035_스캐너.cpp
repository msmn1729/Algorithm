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
#include <cstdlib>
#include <cmath>

using namespace std;

//https://www.acmicpc.net/problem/3035 스캐너
//로직을 떠올리는게 생각처럼 쉽지않음

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c, zr, zc, i, j;
    char s[300][300] = {};
    cin >> r >> c >> zr >> zc;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin >> s[i][j];
        }
    }
    for(i=0; i<r; i++)
    {
        for(int k=0; k<zr; k++)
        {
            for(j=0; j<c; j++)
            {
                for(int l=0; l<zc; l++)
                {
                    cout << s[i][j];
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
