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

//https://www.acmicpc.net/problem/2580 스도쿠
//백트래킹이 익숙치 않아 어려웠음

using namespace std;

int board[9][9], zero_pos[81], zero_cnt;
bool row[9][10], col[9][10], sub_square[9][10];

void solve(int idx)
{
    int i, j;
    if(idx == zero_cnt)
    {
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    //언팩
    int x = zero_pos[idx] / 9; //행번호
    int y = zero_pos[idx] % 9; //열번호
    int z = x / 3 * 3 + y / 3; //서브스퀘어 넘버링
    for(i=1; i<=9; i++) //넣을 숫자
    {
        if(row[x][i] || col[y][i] || sub_square[z][i]) continue; //중복체크
        
        row[x][i] = col[y][i] = sub_square[z][i] = true;
        board[x][y] = i;
        
        solve(idx+1);
        
        board[x][y] = 0;
        row[x][i] = col[y][i] = sub_square[z][i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j, in;
    
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            cin >> in;
            board[i][j] = in;
            if(in > 0)
            {
                row[i][in] = true;
                col[j][in] = true;
                sub_square[i / 3 * 3 + j / 3][in] = true;
            }
            else if(in == 0)
            {
                zero_pos[zero_cnt++] = i * 9 + j; //팩
            }
        }
    }
    solve(0);
}
