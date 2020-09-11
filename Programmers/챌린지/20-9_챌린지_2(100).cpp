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

vector<int> solution(int size) {
    vector<int> answer;
    
    int a[1001][1001] = {};
    int num = 0, x = 0, y = 0;
    int i, j, k;
    
    int m_cnt = (size*(size+1))/2;
    int flag = 0;
    
    for(k=size; k>0; k-=3)
    {
        for(i=0; i<k; i++)
        {
            a[x][y] = ++num;
            x++;
            if(num == m_cnt)
            {
                flag = 1;
                break;
            }
        }
        x--;
        if(flag) break;
        
        for(i=0; i<k-1; i++)
        {
            y++;
            a[x][y] = ++num;
            if(num == m_cnt)
            {
                flag = 1;
                break;
            }
        }
        if(flag) break;
        
        for(i=0; i<k-2; i++)
        {
            x--; y--;
            a[x][y] = ++num;
            if(num == m_cnt)
            {
                flag = 1;
                break;
            }
        }
        x++;
        if(flag) break;
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if(a[i][j]) answer.push_back(a[i][j]);
        }
    }
    return answer;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}
