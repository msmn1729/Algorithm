#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss;
    string word;
    ss.str(s);
    
    while(ss >> word) {        
        for(char& c : word) {
            if(isupper(c)) c = tolower(c);
        }
        if(islower(word[0])) word[0] = toupper(word[0]);
        answer += word + " ";
    }
    if(answer.back() == ' ') answer.pop_back();
    
    return answer;
}
