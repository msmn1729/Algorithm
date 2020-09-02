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
int board[20][20];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, dif_min = 100;
    cin >> n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin >> board[i][j];

    vector<int> team(n, 1);
    for(i=0; i<n/2; i++) //절반씩 0번팀, 1번팀
    {
        team[i] = 0;
    }
    do
    {
        if(team[0] == 1) break;
        vector<int> zero_team;
        vector<int> one_team;
        int zero_team_score = 0;
        int one_team_score = 0;

        for(i=0; i<n; i++)
        {
            if(team[i] == 0) zero_team.push_back(i); //0번팀 투입
            else one_team.push_back(i); //1번팀 투입
        }
        for(i=0; i<n/2; i++)
        {
            for(j=0; j<n/2; j++)
            {
                if(i == j) continue;
                zero_team_score += board[zero_team[i]][zero_team[j]];
                one_team_score += board[one_team[i]][one_team[j]];
            }
        }
        dif_min = min(dif_min, abs(zero_team_score-one_team_score));

    }while(next_permutation(team.begin(), team.end()));

    cout << dif_min;
}
