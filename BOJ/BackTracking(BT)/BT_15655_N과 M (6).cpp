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

//https://www.acmicpc.net/problem/15655 N과 M (6)

int combi[10], visit[10001], num[10];
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
        return;
    }
    for(int i=start; i<n; i++)
    {
        combi[depth] = num[i];
        dfs(i+1, depth+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set< vector<int> > s;
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> num[i];
    }
    sort(num, num+n);
    dfs(0, 0);
    
//    do{
//        vector<int> v;
//        for(int i=0; i<m; i++)
//        {
//            v.push_back(num[i]);
//        }
//        s.insert(v);
//    } while(next_permutation(num, num+n));
//
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
