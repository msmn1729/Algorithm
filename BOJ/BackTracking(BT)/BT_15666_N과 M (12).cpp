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

//https://www.acmicpc.net/problem/15666 N과 M (12)
//set로도 가능하고 없이도 가능함

int n, m;
int combi[10], num[10];
set<vector<int> > s;

void dfs(int start, int depth)
{
    int used = 0;
    if(depth == m)
    {
//        vector<int> tmp;
        for(int i=0; i<m; i++)
        {
            cout << combi[i] << ' ';
//            tmp.push_back(combi[i]);
        }
        cout << '\n';
//        s.insert(tmp);
        return;
    }
    for(int i=start; i<n; i++)
    {
        if(used == num[i]) continue;
        used = num[i];
        combi[depth] = num[i];
        dfs(i, depth+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> num[i];
    }
    sort(num, num+n);
    
    dfs(0, 0);
    
//    for(auto it : s)
//    {
//        for(auto it2 : it)
//        {
//            cout << it2 << ' ';
//        }
//        cout << '\n';
//    }

    return 0;
}
