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

//https://www.acmicpc.net/problem/2752 세수정렬

using namespace std;

int board[9][9], zero_pos[81], zero_cnt;
bool row[9][10], col[9][10], sub_square[9][10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> v;
    for(int i=0; i<3; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    for(int i: v) cout << i << ' ';
   
    return 0;
}
