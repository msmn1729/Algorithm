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

//https://www.acmicpc.net/problem/1405 미친 로봇

int n;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visit[29][29]; //최대 14칸 이동가능하므로
double percent[4];

double dfs(int x, int y, int depth)
{
    if(depth == n) return 1; //깊이가 n
    visit[x][y] = 1; //방문처리

    double result = 0;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visit[nx][ny]) continue;
        result += (percent[i] * dfs(nx, ny, depth+1));
    }
    visit[x][y] = 0;
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<4; i++)
    {
        int a; cin >> a;
        percent[i] = a * 0.01;
    }
    
    cout << fixed; //소수점 자릿수 고정
    cout.precision(10);
    cout << dfs(14, 14, 0);
    
    return 0;
}
