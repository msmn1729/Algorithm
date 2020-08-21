#include <iostream>

using namespace std;

#define R 1
#define L 2
int map[100][100];
int n, m, h;

bool check()
{
    for(int i=0; i<n; i++)
    {
        int col=i;
        for(int row=0; row<=h; row++)
        {
            if(map[row][col] == L) col--;
            else if(map[row][col] == R) col++;
        }
        if(col != i) return false;
    }
    return true;
}

int solve(int idx, int cnt)
{
    if(idx >= n*h || cnt == 3)
    {
        if(check()) return cnt; //끝까지 갔을 때 추가된 사다리 수 반환
        return 2e9; //추가된 사다리 3개이고 check실패한 경우
    }
    int ret = 2e9;
    int row = idx / n;
    int col = idx % n;
    if(col+1 != n && map[row][col] == 0 && map[row][col+1] == 0)
    {
        map[row][col] = R;
        map[row][col+1] = L;
        ret = min(ret, solve(idx+2, cnt+1));
        map[row][col] = map[row][col+1] = 0;
    }
    return min(ret, solve(idx+1, cnt));
}

int main()
{
    cin >> n >> m >> h;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = R;
        map[a-1][b] = L;
    }
    int ans = solve(0, 0);
    if(ans == 2e9) cout << -1;
    else cout << ans;
}
