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
#define ll long long

using namespace std;

void spin(vector<vector<int> > &v) //호출될 때마다 90도씩 회전하는 함수
{
    int size = (int)v.size();
    vector<vector<int> > ans(size);
    int tmp_size = size;
    int x=0, y=0;
    int i, j;
    
    for(i=0; i<size; i++)
    for(j=0; j<size; j++) ans[i].push_back(0); //정답 벡터 크기 확장
    
    while(tmp_size>=1) //사이즈가 1이상인 동안 반복
    {
        for(i=0; i<tmp_size; i++) //1. 상단을 우측으로
        {
            ans[x+i][y+tmp_size-1] = v[x][y+i];
        }
        for(i=1; i<tmp_size; i++) //2. 우측을 하단으로
        {
            ans[x+tmp_size-1][y+tmp_size-1-i] = v[x+i][y+tmp_size-1];
        }
        for(i=1; i<tmp_size; i++) //3. 하단을 좌측으로
        {
            ans[x+tmp_size-1-i][y] = v[x+tmp_size-1][y+tmp_size-1-i];
        }
        for(i=1; i<tmp_size; i++) //4. 좌측을 상단으로
        {
            ans[x][y+i] = v[x+tmp_size-1-i][y];
        }
        tmp_size-=2;
        x++;
        y++;
    }
    
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            v[i][j] = ans[i][j]; //v벡터에 90도 회전된 벡터를 복사
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> v, int r) {
    
    int size = (int)v.size();
    vector<vector<int>> ans(size);
    int i, j;
    r %= 4; //회전횟수 : 4로 나눈 나머지
    
    for(i=0; i<size; i++)
    for(j=0; j<size; j++) ans[i].push_back(0);
    
    for(i=0; i<r; i++) spin(v); //횟수만큼 90도 회전
    
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            ans[i][j] = v[i][j];
        }
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //        solution({{1, 2}, {3, 4}}, 1000000);
    //        solution({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1);
    //        solution({{4, 1, 2}, {7, 3, 4}, {3, 5, 6}}, 3);
    solution({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 1);
    
    return 0;
}
