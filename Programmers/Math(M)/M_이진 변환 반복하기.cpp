#include <bits/stdc++.h>
using namespace std;

int zeroCnt;

string convert(string s) {
    string ret = "";
    int num = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '0') zeroCnt++;
        else num++;
    }
    
    while(num) {
        ret = to_string(num % 2) + ret;
        num /= 2;
    }
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer(2);
    
    // 이진 변환한 횟수
    while(s != "1") {
        answer[0]++;
        s = convert(s);
    }
    
    // 제거한 0의 개수
    answer[1] = zeroCnt;
    
    return answer;
}
