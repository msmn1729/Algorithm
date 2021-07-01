#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
// 같은 영역의 픽셀들을 0으로 바꾸고 그 넓이를 반환
int DFS(vector<vector<int>>& picture, int m, int n, int x, int y) {
    if(x<0 || y<0 || x>=m || y>=n || picture[x][y] == 0) return 0;
    picture[x][y] = 0;
    int area = 1;
    for(int i=0; i<4; i++) area += DFS(picture, m, n, x+dx[i], y+dy[i]);
    return area;
}

void solution(int m, int n, vector<vector<int>> picture) {
    int pic_cnt = 0;
    vector<int> ans;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(picture[i][j] == 0) continue;
            ans.push_back(DFS(picture, m, n, i, j));
            pic_cnt++;
        }
    }
    cout << pic_cnt << '\n';
    sort(ans.begin(), ans.end());
    for(int a : ans) cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            v[i].push_back(s[j] - '0');
        }
    }
    solution(n, n, v);
    
    return 0;
}
