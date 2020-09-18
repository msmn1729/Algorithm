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
#include <sstream>
#include <stdlib.h>

#define MAX_SIZE 1000000
int num[100];
int combi[MAX_SIZE];
int n, s, sum, ans, cnt;

using namespace std;
vector<string> V;

void DFS(int start, int depth)
{
    if(depth > 0) //합과 같으면서 깊이가 1이상인 경우
    {
        for(int i=0; i<depth; i++)
        {
            sum += combi[i];
        }
        if(sum == n)
        {
            char str[100] = {};
            for(int i=0; i<depth; i++)
            {
                str[i] = combi[i] + '0';
            }
            V.push_back(str);
            cnt++;

        }
        sum = 0;

    }
    for(int i=start; i<n; i++)
    {
        for(int j=1; j<=3; j++)
        {
            combi[depth] = j;
            DFS(i+1, depth+1);
        }
    }
}

int main()
{
    //18:07~ 30분 잡고 대결
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);

    int k, flag=0;
    cin >> n >> k;

    ans = 0;
    DFS(0, 0);
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    reverse(V.begin(), V.end());
    while(!V.empty())
    {
        ans++;
//        cout << V.back() << '\n';
        if(ans == k)
        {
            flag=1;
            cout << V.back()[0];
            for(int i=1; i<V.back().length(); i++)
            {
                cout << '+' << V.back()[i];
            }
        }
        V.pop_back();
    }
    if(!flag) cout << -1;
    //cout << V[k-1] << '\n';

}
