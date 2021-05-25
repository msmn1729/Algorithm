#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    string tmp;
    for(int i=0; i<s.size(); i++) {
        if(tmp.back() == s[i]) {
            tmp.pop_back();
            continue;
        }
        tmp += s[i];
    }
    if(tmp.empty()) return 1;
    return 0;
}
