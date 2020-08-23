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

using namespace std;

//https://www.acmicpc.net/problem/16172 나는 친구가 적다 (Large)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char s1[200001]={}, s2[200001]={}, tmp[200001]={};
    cin >> s1 >> s2;
    int len = (int)strlen(s1), idx=0;
    for(int i=0; i<len; i++)
    {
        if(isdigit(s1[i])) continue;
        tmp[idx++] = s1[i];
    }

    if(strstr(tmp, s2) != NULL) cout << 1;
    else cout << 0;

    return 0;
}
