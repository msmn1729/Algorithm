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
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, cnt=0, x[6] = {500, 100, 50, 10, 5, 1}, i;
    cin >> n;
    n = 1000 - n;
    for(i=0; i<6; i++)
    {
        while(n-x[i] >= 0)
        {
            n -= x[i];
            cnt++;
        }
    }
    cout << cnt;
}
