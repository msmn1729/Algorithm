#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
// 같은 영역의 픽셀들을 0으로 바꾸고 그 넓이를 반환
int DFS(vector<vector<int>>& picture, int m, int n, int x, int y) {
    if(x<0 || y<0 || x>=m || y>=n || picture[x][y] == 0) return 0;
    int cur = picture[x][y];
    picture[x][y] = 0;
    int area = 1;
    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
        if(cur != picture[nx][ny]) continue;
        area += DFS(picture, m, n, x+dx[i], y+dy[i]);
    }
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    int pic_cnt = 0, max_area = 0;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(picture[i][j] == 0) continue;
            max_area = max(max_area, DFS(picture, m, n, i, j));
            pic_cnt++;
        }
    }
    answer[0] = pic_cnt;
    answer[1] = max_area;

    return answer;
}
