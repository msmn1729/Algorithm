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

//https://www.acmicpc.net/problem/1021 회전하는 큐
//기본 자료구조 문제~

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    deque<int> dq;
    int n, m;
    int ar[51] = {};
    cin >> n >> m;
    for(int i=0; i<m; i++) cin >> ar[i];
    for(int i=1; i<=n; i++)
    {
        dq.push_back(i);
    }
    int l_ans = 0, r_ans = 0;
    for(int i=0; i<m; i++)
    {
        
        while(dq.size())
        {
            //찾는 숫자의 인덱스 찾기
            int idx=0;
            for(int j=0; j<dq.size(); j++)
            {
                if(ar[i] == dq[j])
                {
                    idx = j;
                    break;
                }
            }
            if(ar[i] == dq.front())
            {
                dq.pop_front();
                break;
            }
            else if(idx <= dq.size()/2) //왼쪽 이동이 더 빠른 경우
            {
                l_ans++;
                int tmp = dq.front();
                dq.push_back(tmp);
                dq.pop_front();
            }
            else //오른쪽 이동이 더 빠른 경우
            {
                r_ans++;
                int tmp = dq.back();
                dq.push_front(tmp);
                dq.pop_back();
            }
        }
    }
    cout << l_ans + r_ans;
    
    return 0;
}
