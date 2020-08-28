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

//https://www.acmicpc.net/problem/1952 달팽이2

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m, n, ar[101][101] = {};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int dir = 0, ans = 0, x = 0, y = 0;
    
    cin >> m >> n;
    while(1) //모든 지점을 방문
    {
        if(ar[x][y] == 1) break;

        ar[x][y] = 1; //방문 처리
        int nx = x + dx[dir]; //다음으로 이동
        int ny = y + dy[dir];
        if(nx<0 || ny<0 || nx>=m || ny>=n || ar[nx][ny] == 1) //다음 좌표로 가지 못하는 경우
        {
            dir = (dir+1)%4;
            ans++;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
    }
    cout << ans-1; //마지막 꺾이는 부분 체크 제외
    return 0;
}
