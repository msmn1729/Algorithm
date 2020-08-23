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

using namespace std;

//https://www.acmicpc.net/problem/15650 N과 M (2)
//next_permutation으로 풀 수도, dfs로 풀 수도 있다!

int combi[10], visit[10];
int n, m;

void dfs(int start, int depth)
{
    if(depth == m)
    {
        for(int i=0; i<m; i++)
        {
            cout << combi[i] << ' ';
        }
        cout << '\n';
    }
    for(int i=start; i<=n; i++)
    {
        if(visit[i]) continue;
        visit[i] = 1;
        combi[depth] = i;
        dfs(i, depth+1);
        visit[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    dfs(1, 0);
//    vector<int> v(n, 1), num;
//    for(int i=1; i<=n; i++) num.push_back(i);
//    for(int i=0; i<m; i++) v[i] = 0;
//
//    do{
//        for(int i=0; i<n; i++)
//        {
//            if(!v[i])
//            {
//                cout << num[i] <<' ';
//            }
//        }
//        cout << '\n';
//    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
