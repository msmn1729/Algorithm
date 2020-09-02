#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool solution(string s) {
    bool answer = false;
    int cnt=0;
    if(4==s.length() || s.length()==6)
    {
        for(int i=0;i<s.length();i++)
        {
            if('0'<=s[i]&&s[i]<='9') cnt++;
        }
        if(cnt==s.length()) answer=true;
    }
    return answer;
}