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

using namespace std;

//https://www.acmicpc.net/problem/5397 키로거
//어려운 문제는 아니지만 생소한 느낌!

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while(t--)
    {
        string s;
        cin >> s;
        list<char> l;
        auto it = l.begin(); //현재 커서의 위치(=다음에 삽입될 원소의 위치)
        
        for(int i=0; s[i]; i++)
        {
            if(s[i] == '<')
            {
                if(it != l.begin()) it--; //커서 좌측 이동가능시
            }
            else if(s[i] == '>')
            {
                if(it != l.end()) it++; //커서 우측 이동가능시
            }
            else if(s[i] == '-')
            {
                if(it != l.begin())
                {
                    it--; //반드시 삭제보다 먼저 해줘야함
                    it = l.erase(it); //it가 가리키는 값을 제거 후 그 다음 원소의 위치를 반환
                }
            }
            else
            {
                l.insert(it, s[i]); //it가 가리키는 곳 앞에 삽입
            }
        }
        for(auto i : l) cout << i;
        cout << '\n';
    }
    
    return 0;
}
