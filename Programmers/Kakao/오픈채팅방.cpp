#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

vector<string> splitMsg(string s) {
    vector<string> msg;
    int prev = 0;
    int cur = 0;
    cur = (int)s.find(" ");
    
    while(cur != string::npos) {
        msg.push_back(s.substr(prev, cur - prev));
        prev = cur + 1;
        cur = (int)s.find(" ", prev);
    }
    msg.push_back(s.substr(prev, cur - prev));
    
    return msg;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    // 맵에 아이디, 닉네임 저장
    map<string, string> m;
    for(string s : record) {
        vector<string> msg = splitMsg(s);
        string command = msg[0];
        string uid = msg[1];
        string nickname;
        
        if(command != "Leave") nickname = msg[2];
        if(command == "Enter") m[uid] = nickname;
        else if(command == "Change") m[uid] = nickname;
    }
    
    // answer에 맵에 있던 아이디의 닉네임 넣기
    for(string s : record) {
        vector<string> msg = splitMsg(s);
        string command = msg[0];
        string uid = msg[1];
        string nickname;
        string answerMsg = "";
        
        if(command != "Leave") nickname = msg[2];
        if(command != "Change") answerMsg += m[uid];
        if(command == "Enter") answerMsg += "님이 들어왔습니다.";
        else if(command == "Leave") answerMsg += "님이 나갔습니다.";
        if(command != "Change") answer.push_back(answerMsg);
    }
    return answer;
}

int main() {
    solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
    
    return 0;
}
