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

//https://programmers.co.kr/learn/courses/30/lessons/42860 조이스틱

int solution(string name)
{
    int ans = 0, i;
    int len = (int)name.size();
    string A_name = "";
    int pos = 0;

    for(i=0; i<len; i++) A_name += 'A';
    while(1)
    {
        int min_gap = min(abs(name[pos] - 'A'), abs(name[pos] - 'Z') + 1);
        ans += min_gap;
        name[pos] = 'A';
        if(A_name == name) break;
        
        int right = 1, left = 1;
        while(name[(pos + right) % len] == 'A') right++;
        while(name[(pos - left + len) % len] == 'A') left++;
        if(right <= left) pos = (pos + right) % len;
        else pos = (pos - left + len) % len;
        ans += min(right, left);
    }
    return ans;
}

int main(void)
{
//        solution("JAZ");
//        solution("JEROEN");
//        solution("JAN");
    solution("BACAZ");
//    solution("BBBAAAB");
    
    return 0;
}
