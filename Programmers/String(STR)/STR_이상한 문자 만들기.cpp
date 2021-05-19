#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            cnt = 0;
            continue;
        }
        if(cnt % 2 == 0) s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
        cnt++;
    }
    answer = s;
    
    return answer;
}
