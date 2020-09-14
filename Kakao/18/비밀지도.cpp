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
#include <bitset>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/17681 비밀지도

vector<int> convert(int dec, int n)
{
    vector<int> v(n);
    for(int i=n-1; i>=0; i--)
    {
        v[i] = dec%2; //2로 나눈 나머지를 배열에 저장
        dec /= 2;
    }
    return v;
}

vector<string> solution(int n, vector<int> ar1, vector<int> ar2)
{
    vector<string> ans;

    for(int i=0; i<ar1.size(); i++) //1, 2크기는 같음
    {
        //10진수 -> 2진수
        vector<int> v1 = convert(ar1[i], n);
        vector<int> v2 = convert(ar2[i], n);

        string s;
        for(int j=0; j<n; j++)
        {
            if(v1[j] || v2[j]) s += '#';
            else s += ' ';
        }
        ans.push_back(s);
    }
    return ans;
}