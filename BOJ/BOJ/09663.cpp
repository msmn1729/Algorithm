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

#define MAX_SIZE 15
int board[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

using namespace std;
vector<string> V;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, j;
    cin >> n;
    
    //visit[1][1] = 1;
    
    queue<pair<int, int> > Q;
    //for(i=0; i<1; i++)
    {
        //for(j=0; j<1; j++)
        {
//            if(visit[i][j] == 1) continue;
            visit[0][0] = 1; //처음 것 방문 처리
            Q.push({0, 0}); //큐에 푸쉬
            
            while(!Q.empty()) //큐가 빌 때까지
            {
//                cout << "QWE";
                auto cur = Q.front();
                Q.pop(); //큐의 맨 앞 팝
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visit[nx][ny] == 1) continue; //가려는 곳이 이미 방문한 곳이면 패스
                    cout << nx << ',' << ny << '\n';
                    visit[nx][ny] = 1; //방문처리
                    Q.push({nx, ny}); //방문한 좌표 큐에 푸쉬
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
}
