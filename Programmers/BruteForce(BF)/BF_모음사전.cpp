#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

string alpa = "AEIOU";
string combi, target;
int cnt, answer;

void go() {
//    cout << cnt << ": " << combi << '\n';
    if(combi == target) {
        answer = cnt;
    }
    cnt++;
    if(combi.length() == 5) {
        combi.pop_back();
        return;
    }
    
    for(int i=0; i<5; i++) {
        combi += alpa[i];
        go();
    }
    combi.pop_back();
}

int solution(string word) {
    target = word;
    go();
    
    return answer;
}

int main() {
    cout << "정답: " << solution("AAAAE");
    return 0;
}
