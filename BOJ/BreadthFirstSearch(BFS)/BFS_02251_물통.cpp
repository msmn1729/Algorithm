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

//https://www.acmicpc.net/problem/2251 물통


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c, water;
    int visit[201][201];
    vector<int> ans;
    cin >> a >> b >> c;
    
    //BFS
    queue<pair<int, int> > q;
    q.push({0, 0});
    visit[0][0] = 1;
    
    while(q.size())
    {
        int cur_a = q.front().first;
        int cur_b = q.front().second;
        int cur_c = c - cur_a - cur_b; //마지막 물의 양을 구할 수 있음
        q.pop();
        if(cur_a == 0) ans.push_back(cur_c); //첫 번째 물통이 비었을 때의 cur_c값 저장
        
        //a -> b
        water = min(cur_a, b - cur_b); //a가 가지고 있는 양과 b의 남은 용량중에 작은 값이 이동하는 물의 양
        if(!visit[cur_a - water][cur_b + water])
        {
            visit[cur_a - water][cur_b + water] = 1;
            q.push({cur_a - water, cur_b + water});
        }
        
        //a -> c
        water = min(cur_a, c - cur_c);
        if(!visit[cur_a - water][cur_b])
        {
            visit[cur_a - water][cur_b] = 1;
            q.push({cur_a - water, cur_b});
        }
        
        //b -> a
        water = min(cur_b, a - cur_a);
        if(!visit[cur_a + water][cur_b - water])
        {
            visit[cur_a + water][cur_b - water] = 1;
            q.push({cur_a + water, cur_b - water});
        }
        
        //b -> c
        water = min(cur_b, c - cur_c);
        if(!visit[cur_a][cur_b - water])
        {
            visit[cur_a][cur_b - water] = 1;
            q.push({cur_a, cur_b - water});
        }
        
        //c -> a
        water = min(cur_c, a - cur_a);
        if(!visit[cur_a + water][cur_b])
        {
            visit[cur_a + water][cur_b] = 1;
            q.push({cur_a + water, cur_b});
        }
        
        //c -> b
        water = min(cur_c, b - cur_b);
        if(!visit[cur_a][cur_b + water])
        {
            visit[cur_a][cur_b + water] = 1;
            q.push({cur_a, cur_b + water});
        }
    }
    
    sort(ans.begin(), ans.end());
    for(int it : ans) cout << it << ' ';
    
    return 0;
}
